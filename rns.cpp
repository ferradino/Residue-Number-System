#include "rns.h"

RNS::RNS(uint32_t moduli[], uint32_t modCount) {
  // Assign moduli and modCount

  // Calculate M
  
  // Calculate m hat
  
  // Calculate inverses

}

RNS::~RNS() {
}

RNSNumber RNS::createRNSNumber(uint32_t num, RNS *rns) {
  uint32_t remainders[mNumModuli];

  for (int i = 0; i < mNumModuli; i++) {
    remainders[i] = num % mModuli[i];
  }
 
  RNSNumber number = RNSNumber(remainders, mNumModuli, rns);
  return number;
}

RNSNumber RNS::createRNSNumber(std::string num, RNS *rns) {
  uint32_t remainders[mNumModuli];

  for (int i = 0; i < mNumModuli; i++) {
    remainders[i] = uint32_t(stoi(num)) % mModuli[i];
  }
 
  RNSNumber number = RNSNumber(remainders, mNumModuli, rns);
  return number;
}

RNSNumber RNS::addRNSNumbers(RNSNumber x, RNSNumber y, RNS *rns) {
  uint32_t *xRemainders = x.getRemainders();
  uint32_t *yRemainders = y.getRemainders();
  uint32_t remainders[mNumModuli];

  for (int i = 0; i < mNumModuli; i++) {
    remainders[i] = (xRemainders[i] + yRemainders[i]) % mModuli[i];
  }

  RNSNumber number = RNSNumber(remainders, mNumModuli, rns);

  mVectorCount++;
  mArithmeticCount += mNumModuli;

  return number;
}

RNSNumber RNS::subRNSNumbers(RNSNumber x, RNSNumber y, RNS *rns) {
  uint32_t *xRemainders = x.getRemainders();
  uint32_t *yRemainders = y.getRemainders();
  uint32_t remainders[mNumModuli];

  for (int i = 0; i < mNumModuli; i++) {
    remainders[i] = (xRemainders[i] + yRemainders[i]) % mModuli[i];
  }

  RNSNumber number = RNSNumber(remainders, mNumModuli, rns);

  mVectorCount++;
  mArithmeticCount += mNumModuli;

  return number;
}


RNSNumber RNS::multRNSNumbers(RNSNumber x, RNSNumber y, RNS *rns) {
  uint32_t *xRemainders = x.getRemainders();
  uint32_t *yRemainders = y.getRemainders();
  uint32_t remainders[mNumModuli];

  for (int i = 0; i < mNumModuli; i++) {
    remainders[i] = (xRemainders[i] + yRemainders[i]) % mModuli[i];
  }

  RNSNumber number = RNSNumber(remainders, mNumModuli, rns);

  mVectorCount++;
  mArithmeticCount += mNumModuli;

  return number;
}

std::string RNS::convertToString(RNSNumber num) {}

uint32_t RNS::getAlpha(RNSNumber num) {}
