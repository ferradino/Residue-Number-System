#include "rns-number.h"
#include <cstdint>

RNSNumber::RNSNumber(uint32_t remainders[], uint32_t numRemainders, RNS *rns) {
  mRNS = rns;
  mRemainders = new uint32_t();
  
  for (int i = 0; i < numRemainders; i++) {
    mRemainders[i] = remainders[i];
  }
}
