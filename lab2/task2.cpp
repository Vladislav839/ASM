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

int NumberOfRoots(int a, int b, int c)
{
	int result;

	__asm
	{
		mov eax, b;
		cdq;
		mov esi, 2;
		idiv esi
		xor esi, esi;
		xor ebp, ebp;
		imul eax;
		mov ebx, eax;
		mov ecx, edx;
		jnc label1;
		mov esi, 1;
	label1:
		mov eax, a;
		imul ecx, c;
		jnc label2;
		mov ebp, 1;
	label2:
		cmp esi, ebp;
		jne label3;
		cmp esi, 0;
		jne label3;
		cmp eax, ecx;
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
	label3:
		cmp esi, ebp;
		je label4;
		cmp esi, 1;
		jne label4;
		mov result, 2;
		jmp end_;
	label4:
		cmp esi, ebp;
		je label5;
		cmp ebp, 1;
		jne label5;
		cmp eax, 0;
		jg l22;
		jl l33;
	l22:
		mov result, 1;
		jmp end_;
	l33:
		mov result, 0;
		jmp end_;
	label5:

	end_:

	}
}

int main()
{
	std::cout << NumberOfRoots(1, 1, -2) << std::endl;
	std::cout << NumberOfRoots(1, 2, 1) << std::endl;
	std::cout << NumberOfRoots(1, 1, 2)<<std::endl;
	system("pause");
	return 0;
}
