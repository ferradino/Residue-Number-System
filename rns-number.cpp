#include "rns-number.h"
#include <cstdint>

RNSNumber::RNSNumber(uint32_t num) {
  mNum = num;
  mRemainders = new uint32_t(mNum);
  
  for (int i = 0; i < mNum - 1; i++) {
    mRemainders[i] = i + 1;
  }
}
