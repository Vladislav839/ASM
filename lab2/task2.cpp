#include <iostream>
#include <cmath>


int Number_Of_Roots(int a, int b, int c)
{
    int result;

    __asm
    {
        mov eax, b;
        sar eax, 1;
        imul eax;
        jnc label1;
        mov esi, 1;
        mov ecx, edx;
    label1:
        mov ebx, eax;
        mov eax, a;
        imul eax, c;
        jnc label2;
        mov ebp, 1;
    label2:
        cmp esi, 1;
        je label3;
        cmp ebp, 1;
        je label3;
        cmp ebx, eax;
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
        cmp esi, 1;
        jne label4;
        cmp ebp, 1;
        je label4;
        mov result, 2;
        jmp end_;
    label4:
        cmp esi, 1;
        je label5;
        cmp ebp, 1;
        jne label5;
        cmp eax, 0;
        jg gr1;
        jl less1;
    gr1:
        mov result, 0;
        jmp end_;
    less1:
        mov result, 2;
        jmp end_;
    label5:
        cmp eax, ebx;
        jg gr2;
        jl less2;
        je eq1;
    gr2:
        mov result, 2;
        jmp end_;
    less2:
        mov result, 0;
        jmp end_;
    eq1:
        cmp ecx, edx;
        jg gr3;
        jl less3;
        je eq2;
    gr3:
        mov result, 2;
        jmp end_;
    less3:
        mov result, 0;
        jmp end_;
    eq2:
        mov result, 1;
        jmp end_;
    end_:

    }
    return result;
}


int main() 
{
    std::cout << Number_Of_Roots(1, pow(2, 31) - 1, 4) << std::endl;
    std::cout << Number_Of_Roots(1, 4, 1) << std::endl;
    system("pause");
    return 0;
}
