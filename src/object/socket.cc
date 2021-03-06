/*
 * Copyright (C) 2009-2012, Gostai S.A.S.
 *
 * This software is provided "as is" without warranty of any kind,
 * either expressed or implied, including but not limited to the
 * implied warranties of fitness for a particular purpose.
 *
 * See the LICENSE file for more information.
 */

#include <urbi/kernel/userver.hh>

#include <urbi/object/global.hh>
#include <object/ioservice.hh>
#include <object/server.hh>
#include <object/socket.hh>
#include <urbi/object/symbols.hh>

#include <runner/job.hh>

#include <eval/send-message.hh>

namespace urbi
{
  namespace object
  {
    Socket::Socket()
      : CxxObject()
      , libport::Socket(*get_default_io_service().get())
      , server_()
      , disconnect_()
      , io_service_(get_default_io_service())
    {
      proto_add(Object::proto);
      // FIXME: call slots_create here when uobjects load order is fixed
    }

    Socket::Socket(rServer server)
      : CxxObject()
      , libport::Socket(*server->getIoService().get())
      , server_(server)
      , disconnect_()
      , io_service_(server->getIoService())
    {
      proto_add(proto);
      init();
    }

    Socket::Socket(rSocket)
      : CxxObject()
      , libport::Socket(*get_default_io_service().get())
      , server_()
      , disconnect_()
      , io_service_(get_default_io_service())
    {
      proto_add(proto);
      // FIXME: call slots_create here when uobjects load order is fixed
    }

    Socket::Socket(rIoService io_service)
      : CxxObject()
      , libport::Socket(*io_service.get())
      , io_service_(io_service)
    {
      proto_add(proto);
      init();
    }

    Socket::~Socket()
    {
      close();
      wasDestroyed();
      while (!checkDestructionPermission())
        ::kernel::runner().yield_for(1000);
    }

    OVERLOAD_TYPE(
      socket_connect_overload, 2, 2,
      String,
      (void (Socket::*)(const std::string&, const std::string&))
      &Socket::connect,
      Float,
      (void (Socket::*)(const std::string&, unsigned))
      &Socket::connect)

    URBI_CXX_OBJECT_INIT(Socket)
      : libport::Socket(*get_default_io_service().get())
      , io_service_(get_default_io_service())
    {
      // Uncomment the line below when overloading works.
      //BIND(connectSerial,
      //     connectSerial, void, (const std::string&, unsigned int))
      BIND(connectSerial, connectSerial,
           void, (const std::string&, unsigned int, bool));
      BIND(disconnect);
      BIND(getAutoRead);
      BIND(getIoService);
      BINDG(host);
      BIND(init);
      BINDG(isConnected);
      BINDG(localHost);
      BINDG(localPort);
      BIND(openFile);
      BIND(poll);
      BINDG(port);
      BIND(read);
      BIND(readOnce);
      BIND(setAutoRead);
      BIND(syncWrite);
      BIND(write);
      setSlot(SYMBOL(connect), new Primitive(socket_connect_overload));
    }

    void
    Socket::init()
    {
      slots_create();
    }

#define BOUNCE(Type, From, To)                  \
    Type                                        \
    Socket::From() const                        \
    {                                           \
      if (isConnected())                        \
        return To();                            \
      else                                      \
        RAISE("unconnected socket");            \
    }
    BOUNCE(std::string, host, getRemoteHost);
    BOUNCE(unsigned short, port, getRemotePort);
    BOUNCE(std::string, localHost, getLocalHost);
    BOUNCE(unsigned short, localPort, getLocalPort);
#undef BOUNCE

    void
    Socket::slots_create()
    {
      CAPTURE_GLOBAL(Event);

#define EVENT(Name)                             \
      {                                         \
        rObject val = Event->call(SYMBOL(new)); \
        slot_set_value(Name, val);              \
      }

      EVENT(SYMBOL(connected));
      EVENT(SYMBOL(disconnected));
      EVENT(SYMBOL(error));
      EVENT(SYMBOL(received));
#undef EVENT

    }

    void
    Socket::connect(const std::string& host, const std::string& port)
    {
      if (boost::system::error_code err = libport::Socket::connect(host, port))
        RAISE(err.message());
    }

    void
    Socket::connect(const std::string& host, unsigned port)
    {
      if (boost::system::error_code err = libport::Socket::connect(host, port))
        RAISE(err.message());
    }

    void
    Socket::connectSerial(const std::string& device, unsigned int baudrate)
    {
      connectSerial(device, baudrate, true);
    }

    void
    Socket::connectSerial(const std::string& device, unsigned int baudrate,
                          bool asyncRead)
    {
      if (boost::system::error_code error =
          libport::Socket::open_serial(device, baudrate, asyncRead))
        RAISE(error.message());
    }

    void
    Socket::disconnect()
    {
      close();
    }

#define EMIT(Name)                              \
    slot_get_value(SYMBOL_(Name))->call(SYMBOL(emit))
#define EMIT1(Name, Arg)                                        \
    slot_get_value(SYMBOL_(Name))->call(SYMBOL(emit), to_urbi(Arg))

    void
    Socket::onConnect()
    {
      disconnect_ = slot_get_value(SYMBOL(connected))->call(SYMBOL(trigger));
      if (server_)
        server_->socket_ready(this);
    }

    void
    Socket::onError(boost::system::error_code err)
    {
      EMIT1(error, err.message());
      EMIT(disconnected);
      aver(disconnect_);
      disconnect_->call(SYMBOL(stop));
    }

    bool
    Socket::isConnected() const
    {
      return libport::Socket::isConnected();
    }

    size_t
    Socket::onRead(const void* data, size_t length)
    {
      bool mustExit = false;
      std::string str(reinterpret_cast<const char*>(data), length);
      try
      {
        if (slot_has(SYMBOL(receive)))
          call(SYMBOL(receive), to_urbi(str));
        else
          EMIT1(received, str);
      }
      catch(const UrbiException& e)
      {
        mustExit = true;
        eval::show_exception(e);
      }
      catch(const std::exception& e)
      {
        mustExit = true;
        eval::send_error((std::string)"Unexpected exception caught: " + e.what());
      }
      catch(...)
      {
        eval::send_error("Unknown exception caught");
      }
      if (mustExit)
      {
        eval::send_error("Exceptiong caught in receive, closing connection.");
        close();
      }
      return length;
    }

    void
    Socket::write(const std::string& data)
    {
      if (!isConnected())
        RAISE("socket not connected");
      libport::Socket::send(data);
    }

    void
    Socket::syncWrite(const std::string& data)
    {
      if (!isConnected())
        RAISE("socket not connected");
      libport::Socket::syncWrite(data);
    }

    std::string
    Socket::read(size_t len)
    {
      return libport::Socket::syncRead(len);
    }

    void
    Socket::readOnce()
    {
      libport::Socket::readOnce();
    }

    void
    Socket::poll()
    {
      getIoService()->poll();
    }

    rIoService
    Socket::getIoService() const
    {
      return io_service_;
    }
    rIoService
    Socket::get_default_io_service()
    {
      static rIoService ios(new IoService);
      return ios;
    }

    void
    Socket::setAutoRead(bool enable)
    {
      libport::Socket::setAutoRead(enable);
    }

    bool
    Socket::getAutoRead()
    {
      return libport::Socket::getAutoRead();
    }

    void
    Socket::openFile(const std::string&s, int m)
    {
      libport::Socket::open_file(s, (libport::Socket::OpenMode)m);
    }
  }
}
