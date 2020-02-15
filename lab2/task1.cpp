#include <iostream>
#include <cmath>

bool isTriangle(int a, int b, int c) {
  int res = 0;

  __asm {
	  mov eax, a;
	  mov ebx, b;
	  mov ecx, c;
	  cmp eax, ecx
	  jg swap1
	  jmp end_1
  swap1:
	  mov edx, eax;
	  mov eax, ecx;
	  mov ecx, edx;
	  jmp end_1;
  end_1:
	  cmp eax, ebx;
	  jg swap2
	  jmp end_2
  swap2:
	  mov edx, eax;
	  mov eax, ebx;
	  mov ebx, edx;
	  jmp end_2
  end_2:
	  cmp ebx, ecx
	  jg swap3
	  jmp end_
  swap3:
	  mov edx, ebx;
	  mov ebx, ecx;
	  mov ecx, edx;
	  jmp end_
  end_:
	  sub ecx, ebx
      cmp ecx, eax
      jl comparison
	  jmp final_
  comparison:
	  mov res, 1
	  jmp final_
  final_:

  }

  return res;
}

int main()
{
  std::cout << isTriangle(3, 4, 5) << std::endl;
  std::cout << isTriangle(pow(2, 31) - 1, pow(2, 31) - 2, pow(2, 31) - 3) << std::endl;
  std::cout << isTriangle(3, 5, 1) << std::endl;
  system("pause");
  return 0;
}
