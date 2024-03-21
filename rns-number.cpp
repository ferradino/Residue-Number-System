#include "rns-number.h"
#include <cstdint>

RNSNumber::RNSNumber(uint32_t remainders[], RNS *rns) {
  int n = sizeof(&remainders) / sizeof(remainders[0]); 
  mRNS = rns;
  mRemainders = new uint32_t(n);
  
  for (int i = 0; i < n; i++) {
    mRemainders[i] = remainders[i];
  }
}
