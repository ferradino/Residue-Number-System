#include <iostream>
#include "rns.h"
#include "rns-number.h"

int main() {
  uint32_t moduli[] = {3, 5, 7};
  uint32_t modCount = 3;
  
  RNS rns = RNS(moduli, modCount);
  RNSNumber num1 = rns.CreateRNSNumber(4);
  RNSNumber num2 = rns.CreateRNSNumber("8");

  RNSNumber num3 = rns.AddRNSNumbers(num1, num2);
  RNSNumber num4 = rns.SubRNSNumbers(num1, num2);
  RNSNumber num5 = rns.MultRNSNumbers(num1, num2);

  std::cout << "Vector: " << rns.GetVectorCount() << std::endl;
  std::cout << "Arithmetic: " << rns.GetArithmeticCount() << std::endl;

  std::cout << "Alpha of RNSNumber: " << rns.ComputeAlpha(num1  ) << std::endl;

  return 0;
}
