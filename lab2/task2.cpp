#include <iostream>

int NumberOfRoots(int a, int b, int c)
{
	int result;

	__asm 
	{
		mov eax, b;
		imul eax;
		mov ebx, a;
		imul ebx, c;
		imul ebx, 4;
		sub eax, ebx;
		cmp eax, 0;
		jg l1;
		je l2;
		jl l3;
	l1:
		mov result, 2;
		jmp end_;
	l2:
		mov result, 1;
		jmp end_;
	l3:
		mov result, 0;
		jmp end_;
	end_:

	}
	return result;
}

int main()
{
	std::cout << NumberOfRoots(1, 1, -2) << std::endl;
	std::cout << NumberOfRoots(1, 2, 1) << std::endl;
	std::cout << NumberOfRoots(1, 1, 2)<<std::endl;
	system("pause");
	return 0;
}
