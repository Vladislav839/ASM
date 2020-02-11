#include <iostream>

int Discriminant(int a, int b, int c) {
  int result;

  __asm {
	  mov eax, b;
	  imul eax;
	  mov ebx, a;
      imul ebx, c;
	  imul ebx, 4;
	  sub eax, ebx;
	  mov result, eax;
  }
  return result;
}

int main() {
  int a, b, c;
  std::cout << "Enter values\n";
  std::cin >> a >> b >> c;
  std::cout << "Discriminant: " << Discriminant(a,b,c) << "\n";
  system("pause");
  return 0;
}
