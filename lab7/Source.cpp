#include <cctype>
#include <iostream>

extern "C" {
int __cdecl TrimAll(char* str);
bool __stdcall IsWhitespace(char s);
}

int main() {
  char str[] = "   bsndb   j ihijoi   jiojilk  lkhlkhl   ";
  std::cout << strlen(str) << std::endl;
  std::cout << str << std::endl;
  int res = TrimAll(str);
  std::cout << str << std::endl;
  std::cout << res << std::endl;
  system("pause");
  return 0;
}
