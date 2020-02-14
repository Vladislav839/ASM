#include <iostream>

int factorial(int num) {
  int res;

  __asm {
	  mov ecx, num
	  mov eax, 1
	  mov ebx, 1
  beg:
	  cmp ebx, ecx
      jge end
	  add ebx, 1
      mul ebx
	  jmp beg
	  
  end:
	  mov res, eax;
  }
  return res;
}

int main() {
  std::cout << factorial(0) << std::endl;
  std::cout << factorial(1) << std::endl;
  std::cout << factorial(2) << std::endl;
  std::cout << factorial(3) << std::endl;
  std::cout << factorial(4) << std::endl;
  std::cout << factorial(5) << std::endl;
  std::cout << factorial(6) << std::endl;
  std::cout << factorial(7) << std::endl;
  system("pause");
  return 0;
}
