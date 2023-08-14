#include <string>
#include <vector>

namespace urbi
{
  int init_kernel(std::string pgm, std::vector<std::string> const& args);
  int init_kernel_mean(const char* pgm);
  unsigned long step_kernel();
  void load_file(std::string const& file);
  void send_command(std::string const & us);
  void kill_kernel();
  void set_ghost_mirror(std::function<void (const char*, size_t)> func);
}