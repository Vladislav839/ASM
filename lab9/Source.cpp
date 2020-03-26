#include <iostream>
#include <iomanip>

extern "C" double __cdecl IntegrateCotan(int n);
int main() {
  std::cout << std::fixed << IntegrateCotan(10) << std::endl;
  std::cout << std::fixed << IntegrateCotan(100) << std::endl;
  std::cout << std::fixed << IntegrateCotan(1000) << std::endl;
  system("pause");
  return 0;
}
