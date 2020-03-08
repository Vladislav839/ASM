#include <iostream>

extern "C"
{
    int __cdecl LastIndexOf(char* source, char* substring);
}


int main()
{
    char* str = new char[256];
    std::cin >> str;
    char* substring = new char[256];
    std::cin >> substring;
    int res;
    __asm
    {
        mov eax, substring;
        push eax;
        mov eax, str;
        push eax;
        call LastIndexOf;
        add esp, 8;
        mov res, eax;
    }
    std::cout << res << std::endl;
    system("pause"); 
    return 0;
}
