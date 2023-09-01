cmake_minimum_required(VERSION 3.22)
project(kernel)
add_definitions(-DHAVE_BOOST=1 -DBOOST_ALL_NO_LIB)
#add_compile_options(/Wall)
add_subdirectory(libport)

if (STATIC_BUILD)
  set(LIB_MODE STATIC)
  add_definitions(-DSTATIC_BUILD=1)
else()
  set(LIB_MODE SHARED)
endif()

find_package(Boost REQUIRED COMPONENTS chrono thread system filesystem date_time regex)
#find python
find_program(_python_executable
    NAMES py python3 python python.exe
    NO_CMAKE_FIND_ROOT_PATH)
  if (NOT _python_executable)
    qi_error("needs python executable in PATH")
  endif()


include_directories(${Boost_INCLUDES})
add_definitions(-DBOOST_ALL_NO_LIBS)
add_definitions(-DBOOST_BIND_GLOBAL_PLACEHOLDERS)

if (WITH_EMBED)
set(U_FILES
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/pubsub.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/require-file.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/stack-frame.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/trajectory-generator.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/code.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/logger.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/string.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/float.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/event.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/boolean.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/directory.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/traceable.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/local.mk
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/process.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/package-info/urbi.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/package-info/libport.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/monitoring.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/comparable.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/group.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/singleton.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/call-message.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/tuple.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/dataflow.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/container.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/lobby.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/tag.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/formatter.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/pattern.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/component.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/object.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/python.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/urbi.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/file.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/run-test.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/job.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/lazy.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/test-suite.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/loadable.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/semaphore.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/system.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/path.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/dictionary.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/math.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/naming-standard.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/duration.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/weak-pointer.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/utags.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/enumeration.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/timeout.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/global.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/vector.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/regexp.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/input-stream.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/list.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/range-iterable.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/package-info.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/updatehook-stack.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/mutex.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/orderable.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/channel.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/profile.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/uobject.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/control.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/kernel1.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/platform.u.in
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/socket.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/date.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/binary.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/nil.u
${CMAKE_CURRENT_SOURCE_DIR}/share:urbi/exception.u
${CMAKE_CURRENT_BINARY_DIR}/share:urbi/platform.u
)
  set(EMBED_SOURCES ${CMAKE_CURRENT_BINARY_DIR}/src/kernel/embed.hh)
  add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/src/kernel/embed.hh
    COMMAND ${_python_executable} ${CMAKE_CURRENT_SOURCE_DIR}/dev/embed.py ${CMAKE_CURRENT_BINARY_DIR}/src/kernel/embed.hh none ${U_FILES}
   DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/share/urbi/platform.u
   )
  add_definitions(-DURBI_WITH_EMBED)
else()
  set(EMBED_SOURCES "")
endif()

add_subdirectory(sdk-remote)

configure_file(
   ${CMAKE_CURRENT_SOURCE_DIR}/include/urbi/kernel/config.h.in
   ${CMAKE_CURRENT_BINARY_DIR}/include/urbi/kernel/config.h
)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sdk-remote/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sdk-remote/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sdk-remote/libport/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/sdk-remote/libport/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include/urbi)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libport/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/libport/include)
if (USE_BOOST_CORO)
  add_definitions(-DSCHED_USE_BOOST_CORO)
endif()

add_definitions(-DLIBPORT_LIBSFX="")
add_definitions(-DLIBPORT_LIBDIRNAME="lib")
add_definitions(-D_USE_MATH_DEFINES)
#add_definitions(/w)

# stack allocation seems to produce weird things on atom builds
if (I_AM_A_ROBOT)
  add_definitions(-DURBI_NO_VLENGTH_ARRAY)
endif ()


if (HAVE_CUSTOM_BISON)

MESSAGE("Using bison")

#invoke flex on utoken.l
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc.raw
  COMMAND flex -+ -o${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc.raw ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/utoken.l
  DEPENDS src/parser/utoken.l
  )

#fix flex output
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc
  COMMAND ${_python_executable} ${CMAKE_CURRENT_SOURCE_DIR}/dev/fix-utoken.py ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc.raw ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc.raw
)

# You need a bison patched by gostai, in the urbi-sdk/bison repository.
set(BISON_OPTS
  --defines --report=all -xml
)
set(BISON
  bison
)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/src/parser/ugrammar.cc
  COMMAND ${BISON} ${BISON_OPTS} ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/ugrammar.y -o  ${CMAKE_CURRENT_BINARY_DIR}/src/parser/ugrammar.cc
  DEPENDS src/parser/ugrammar.y
 )

function(astgen target command)
 add_custom_command(
  OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${target}
  COMMAND ${_python_executable} ${CMAKE_CURRENT_SOURCE_DIR}/dev/ast-${command}-gen ${CMAKE_CURRENT_SOURCE_DIR}/src/ast < ${CMAKE_CURRENT_SOURCE_DIR}/src/ast/ast.yml
  DEPENDS src/ast/ast.yml
 )
endfunction()


astgen(src/ast/all.cc all)
astgen(src/ast/cloner.cc cloner)
astgen(src/ast/transformer.cc transformer)
astgen(src/ast/fwd.hh fwd)
astgen(src/ast/default-visitor.hh default-visitor)
astgen(src/ast/visitor.hh visitor)
astgen(src/ast/pretty-printer.cc pretty-printer)
astgen(src/ast/dot-printer.cc dot-printer)
astgen(src/ast/serializer.hh serializer)
astgen(src/ast/implicit.hh nodes)

set(GENERATED_SRC
  src/ast/visitor.hh
  src/ast/implicit.hh
  src/ast/all.cc
  src/ast/cloner.hxx
  src/ast/cloner.cc
  src/ast/dot-printer.cc
  src/ast/pretty-printer.cc
  src/ast/transformer.cc
  src/ast/default-visitor.hh
  src/ast/fwd.hh
)

else()
  MESSAGE("No bison specified, using pregenerated grammar and AST files.")
  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/src/parser/ugrammar.cc
    ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/pregenerated/ ${CMAKE_CURRENT_BINARY_DIR}/src/parser/
    DEPENDS src/parser/ugrammar.y src/ast/ast.yml src/parser/pregenerated/ugrammar.cc
  )

  # HACK, to avoid a qi_generate_src rule for all 100 files,
  # merge the ccs into one merged.cc and declare arule just for it
  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/ast/merged.cc
    COMMAND ${CMAKE_COMMAND} -E copy_directory   ${CMAKE_CURRENT_SOURCE_DIR}/src/ast/pregenerated/ ${CMAKE_CURRENT_SOURCE_DIR}/src/ast/
    DEPENDS src/ast/ast.yml
     )
  set(GENERATED_SRC
    src/ast/merged.cc
  )

endif(HAVE_CUSTOM_BISON)


set(UOBJECT_PLUGIN_SRC
${CMAKE_CURRENT_BINARY_DIR}/include/urbi/kernel/config.h
${GENERATED_SRC}
src/ast/analyzer.cc
src/ast/analyzer.hh
src/ast/catches-type.cc
src/ast/catches-type.hh
src/ast/dot-print.cc
src/ast/dot-print.hh
src/ast/event-match.cc
src/ast/event-match.hh
src/ast/event-match.hxx
src/ast/exps-type.cc
src/ast/exps-type.hh
src/ast/factory.cc
src/ast/factory.hh
src/ast/flavor.cc
src/ast/flavor.hh
src/ast/flavor.hxx
src/ast/formal.cc
src/ast/formal.hh
src/ast/loc.cc
src/ast/loc.hh
src/ast/local-declarations-type.cc
src/ast/local-declarations-type.hh
src/ast/nary-fwd.hh
src/ast/new-clone.hh
src/ast/new-clone.hxx
src/ast/parametric-ast.cc
src/ast/parametric-ast.hh
src/ast/parametric-ast.hxx
src/ast/print.cc
src/ast/print.hh
src/ast/symbols-type.cc
src/ast/symbols-type.hh
src/binder/bind.cc
src/binder/bind.hh
src/binder/binder.cc
src/binder/binder.hh
src/binder/binder.hxx
src/binder/fwd.hh
src/console-server.cc
src/eval/action.hh
src/eval/ast.cc
src/eval/ast.hh
src/eval/ast.hxx
src/eval/call.cc
src/eval/call.hh
src/eval/call.hxx
src/eval/exec.hh
src/eval/exec.hxx
src/eval/fwd.hh
src/eval/raise.cc
src/eval/raise.hh
src/eval/send-message.cc
src/eval/send-message.hh
src/eval/send-message.hxx
src/flower/flow.cc
src/flower/flow.hh
src/flower/flower.cc
src/flower/flower.hh
src/kernel/connection-set.cc
src/kernel/connection-set.hh
src/kernel/connection.cc
src/kernel/connection.hh
src/kernel/server-timer.cc
src/kernel/server-timer.hh
src/kernel/uconnection.cc
src/kernel/ughostconnection.cc
src/kernel/ughostconnection.hh
src/kernel/uobject.cc
src/kernel/uobject.hh
src/kernel/userver.cc
src/kernel/utypes.cc
src/kernel/uvalue-cast.cc
src/kernel/uvalue-cast.hh
src/object/barrier.cc
src/object/centralized-slots.cc
src/object/code.cc
src/object/code.hh
src/object/cxx-helper.hh
src/object/cxx-object.cc
src/object/date.cc
src/object/dictionary.cc
src/object/directory.cc
src/object/duration.cc
src/object/event-handler.cc
src/object/event.cc
src/object/executable.cc
src/object/file.cc
src/object/finalizable.cc
src/object/finalizable.hh
src/object/float.cc
src/object/format-info.cc
src/object/format-info.hh
src/object/format-info.hxx
src/object/formatter.cc
src/object/formatter.hh
src/object/global.cc
src/object/hash-slots.hh
src/object/hash-slots.hxx
src/object/hash.cc
src/object/ioservice.cc
src/object/ioservice.hh
src/object/job.cc
src/object/list.cc
src/object/lobby.cc
src/object/local.mk
src/object/location.cc
src/object/matrix.cc
src/object/object-class.cc
src/object/object-class.hh
src/object/object-size.cc
src/object/object.cc
src/object/path.cc
src/object/position.cc
src/object/primitive.cc
src/object/profile.cc
src/object/profile.hh
src/object/register.cc
src/object/root-classes.cc
src/object/root-classes.hh
src/object/semaphore.cc
src/object/semaphore.hh
src/object/server.cc
src/object/server.hh
src/object/slot.cc
src/object/socket.cc
src/object/socket.hh
src/object/sorted-vector-slots.hh
src/object/sorted-vector-slots.hxx
src/object/string.cc
src/object/subscription.cc
src/object/symbols.cc
src/object/system.cc
src/object/system.hh
src/object/tag.cc
src/object/uconnection.cc
src/object/uconnection.hh
src/object/urbi-exception.cc
src/object/uvalue.cc
src/object/uvalue.hh
src/object/vector-slots.hh
src/object/vector-slots.hxx
src/object/vector.cc
src/parser/flex-lexer.hh
src/parser/fwd.hh
src/parser/is-keyword.cc
src/parser/is-keyword.hh
src/parser/metavar-map.hh
src/parser/metavar-map.hxx
src/parser/parse.cc
src/parser/parse.hh
src/parser/parser-impl.cc
src/parser/parser-impl.hh
src/parser/parser-impl.hxx
src/parser/parser-utils.cc
src/parser/parser-utils.hh
src/parser/transform.cc
src/parser/transform.hh
src/parser/uparser.cc
src/parser/uparser.hh
src/parser/utoken.hh
${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc
src/parser/ugrammar.cc
src/rewrite/desugarer.cc
src/rewrite/desugarer.hh
src/rewrite/fwd.hh
src/rewrite/pattern-binder.cc
src/rewrite/pattern-binder.hh
src/rewrite/rescoper.cc
src/rewrite/rescoper.hh
src/rewrite/rewrite.cc
src/rewrite/rewrite.hh
src/runner/exception.cc
src/runner/exception.hh
src/runner/job.cc
src/runner/job.hh
src/runner/job.hxx
src/runner/local.mk
src/runner/raise.cc
src/runner/shell.cc
src/runner/shell.hh
src/runner/sneaker.cc
src/runner/sneaker.hh
src/runner/stacks.cc
src/runner/stacks.hh
src/runner/stacks.hxx
src/runner/state.cc
src/runner/state.hh
src/runner/state.hxx
src/urbi/iostream.cc
src/urbi/iostream.hh
src/urbi/sdk.cc
# Build in rObject modules, they require exported data symbols.
src/object/urbi/logger.cc
src/object/urbi/regexp.cc
src/object/urbi/stream.cc
src/object/urbi/input-stream.cc
src/object/urbi/output-stream.cc
# Needed by system.cc
sdk-remote/src/libuco/urbi-main.cc
sdk-remote/src/liburbi/urbi-root.cc
sdk-remote/src/liburbi/urbi-launch.cc
)


set(UCO_SRC
sdk-remote/src/libuco/details.cc
sdk-remote/src/libuco/local.mk
sdk-remote/src/libuco/uevent.cc
sdk-remote/src/libuco/uobject-common.cc
sdk-remote/src/libuco/uobject-hub-common.cc
sdk-remote/src/libuco/uprop.cc
sdk-remote/src/libuco/ustarter.cc
sdk-remote/src/libuco/utable.cc
sdk-remote/src/libuco/uvar-common.cc
sdk-remote/src/libuco/version-check.cc
sdk-remote/src/libuvalue/exit.cc
sdk-remote/src/libuvalue/package-info.cc
sdk-remote/src/libuvalue/ubinary.cc
sdk-remote/src/libuvalue/uimage.cc
sdk-remote/src/libuvalue/ulist.cc
sdk-remote/src/libuvalue/usound.cc
sdk-remote/src/libuvalue/uvalue-common.cc
)


if (APPLE)
  # Workaround clang bug http://llvm.org/bugs/show_bug.cgi?id=14116
  set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O1")
endif()

if (NOT WIN32)
  list(APPEND UOBJECT_PLUGIN_SRC src/object/urbi/process.cc)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include/urbi/parser/)


# For ast/factory.cc
add_definitions(-D__SRCDIR__="")
add_definitions(-DBUILDING_URBI_SDK -DBUILDING_URBI_MODULE)

# uobject-remote is renamed as uobject using a set_target_properties
# but this one needs to be correct, because DEPENDS does not honor OUTPUT_NAME

add_library(uobject
  ${LIB_MODE}
  ${UCO_SRC} ${UOBJECT_PLUGIN_SRC} ${EMBED_SOURCES}
)
target_link_libraries(uobject
  port sched serialize Boost::filesystem Boost::date_time Boost::system Boost::thread Boost::regex
)
set_target_properties(uobject
  PROPERTIES
     OUTPUT_NAME uobject
     INSTALL_NAME_DIR "@executable_path/../lib/gostai/engine"
     COMPILE_FLAGS -DBUILDING_URBI_SDK
     INSTALL_RPATH "$ORIGIN/../..")


install(TARGETS uobject DESTINATION lib/gostai/engine)

if (MSVC AND STATIC_BUILD)
add_custom_target(uobject-full ALL
	lib.exe
		/out:${CMAKE_CURRENT_BINARY_DIR}/uobject-full.lib
		$<TARGET_FILE:uobject>
		$<TARGET_FILE:port>
		$<TARGET_FILE:sched>
		$<TARGET_FILE:serialize>
		${Boost_SYSTEM_LIBRARY_RELEASE}
		${Boost_THREAD_LIBRARY_RELEASE}
		${Boost_FILESYSTEM_LIBRARY_RELEASE}
	BYPRODUCTS uobject-full.lib
)
add_dependencies(uobject-full uobject)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/uobject-full.lib
	DESTINATION lib)
endif()

if (UNIX AND STATIC_BUILD)
add_custom_target(libuobject-full ALL
       ${CMAKE_CURRENT_SOURCE_DIR}/dev/assemble-libs.sh
		${CMAKE_CURRENT_BINARY_DIR}/libuobject-full.a
		$<TARGET_FILE:uobject>
		$<TARGET_FILE:port>
		$<TARGET_FILE:sched>
		$<TARGET_FILE:serialize>
		${Boost_SYSTEM_LIBRARY_RELEASE}
		${Boost_THREAD_LIBRARY_RELEASE}
		${Boost_FILESYSTEM_LIBRARY_RELEASE}
	BYPRODUCTS uobject-full.a
)
add_dependencies(libuobject-full uobject)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libuobject-full.a
	DESTINATION lib)
endif()

add_executable(urbiscript
  sdk-remote/src/liburbi/urbi.cc  $<TARGET_OBJECTS:uobject>
  )
target_link_libraries(urbiscript 
  port sched serialize Boost::filesystem Boost::date_time Boost::system Boost::thread Boost::regex
  )
install(TARGETS urbiscript)
# Add a simple test:
enable_testing()

#Built-in due to symbol exporting problems
#add_subdirectory(src/object/urbi)

add_subdirectory(share)
#Requires lib uobject
add_subdirectory(sdk-remote/src/uobjects)
if (NOT I_AM_A_ROBOT)
#  add_subdirectory(sdk-remote/src/swig/java)
endif()
add_subdirectory(tests)
