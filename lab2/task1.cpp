#include <iostream>

bool isTriangle(int a, int b, int c)
{
	int result = 0;
	__asm
	{
		mov eax, a;
		mov ebx, result;
		add eax, b;
		cmp eax, c;
		jg label1
		jmp end_;
	label1:
		add ebx, 1;
		mov eax, b;
		add eax, c;
		cmp eax, a;
		jg label2
		jmp end_;
	label2:
		add ebx, 1;
		mov eax, a;
		add eax, c;
		cmp eax, b;
		jg label3 
		jmp end_;
	label3:
		mov ebx, 1;
		mov result, ebx;
	end_:
	}
	return result;
}

int main()
{
  std::cout << isTriangle(3, 4, 10) << std::endl;
	system("pause");
	return 0;
}
