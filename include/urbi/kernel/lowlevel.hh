#include <string>
#include <vector>

namespace urbi
{
  int init_kernel(std::string pgm, std::vector<std::string> const& args);
  int init_kernel_mean(const char* pgm);
  unsigned long step_kernel();
  void kill_kernel();
}