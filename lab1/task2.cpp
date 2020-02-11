#include <iostream>
int Evaluate(int a, int b, int* remainder) {
  int quotient;
  int temp;

  __asm {
		mov eax, b;
		neg eax;
		cdq;
		mov esi, a;
		idiv esi;
		mov quotient, eax;
		mov temp, edx; 
  }
  *remainder = temp;
   return quotient;
}

int main() {
  int a, b;
  std::cout << "a b:" << std::endl << "> ";
  std::cin >> a >> b;

  if (b != 0) {
    int remainder;
    auto quotient = Evaluate(a, b, &remainder);
    std::cout << "res = " << quotient << " + " << remainder << "/" << abs(a)
              << std::endl;
  }
  system("pause");
}
