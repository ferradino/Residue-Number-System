#include "rns.h"

uint32_t findInverse(int32_t a, int32_t n) {
  int32_t t = 0;
  int32_t newt = 1;
  int32_t r = n;
  int32_t newr = a;

  while (newr != 0) {
    int32_t q = r / newr;

    t = newt;
    newt = t - q * newt;

    r = newr;
    newr = r - q * newr;
  }

  if (r > 1) {
    std::cout << a << " is not invertiable! Exiting Program!" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  if (t < 0) {
    t = t + n;
  }

  return uint32_t(t);
}

RNS::RNS(uint32_t moduli[], uint32_t modCount) {
  mModulus = new uint32_t(modCount);
  mMHat = new uint32_t(modCount);
  mMHatInverse = new uint32_t(modCount);
  mRInverse = new uint32_t(modCount);

  mNumModuli = modCount; 

  for (int i = 0; i < mNumModuli; i++) {
    mModulus[i] = moduli[i];
    mM *= moduli[i];
  }
  
  for (int j = 0; j < mNumModuli; j++) {
    mMHat[j] = mM / mModulus[j];
  }

  for (int k = 0; k < mNumModuli; k++) {
    // mMHatInverse[k] = findInverse();
  }

}

RNS::~RNS() {
  delete [] mModulus;
  delete [] mMHat;
  delete [] mMHatInverse;
  delete [] mRInverse;
}

RNSNumber RNS::createRNSNumber(uint32_t num, RNS *rns) {
  uint32_t remainders[mNumModuli];

  for (int i = 0; i < mNumModuli; i++) {
    remainders[i] = num % mModulus[i];
  }
 
  RNSNumber number = RNSNumber(remainders, rns);
  return number;
}

RNSNumber RNS::createRNSNumber(std::string num, RNS *rns) {
  uint32_t remainders[mNumModuli];

  for (int i = 0; i < mNumModuli; i++) {
    remainders[i] = uint32_t(stoi(num)) % mModulus[i];
  }
 
  RNSNumber number = RNSNumber(remainders, rns);
  return number;
}

RNSNumber RNS::addRNSNumbers(RNSNumber x, RNSNumber y, RNS *rns) {
  uint32_t *xRemainders = x.getRemainders();
  uint32_t *yRemainders = y.getRemainders();
  uint32_t remainders[mNumModuli];

  if (x.getRNS() != y.getRNS()) {
    std::cout << "Modular arithmetic performed on RNSNumbers that  are not apart of the same RNS! Exiting Program!" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  for (int i = 0; i < mNumModuli; i++) {
    remainders[i] = (xRemainders[i] + yRemainders[i]) % mModulus[i];
  }

  mVectorCount++;
  mArithmeticCount += mNumModuli;

  return RNSNumber(remainders, rns);
}

RNSNumber RNS::subRNSNumbers(RNSNumber x, RNSNumber y, RNS *rns) {
  uint32_t *xRemainders = x.getRemainders();
  uint32_t *yRemainders = y.getRemainders();
  uint32_t remainders[mNumModuli];
  
  if (x.getRNS() != y.getRNS()) {
    std::cout << "Modular arithmetic performed on RNSNumbers that  are not apart of the same RNS! Exiting Program!" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  for (int i = 0; i < mNumModuli; i++) {
    remainders[i] = (xRemainders[i] + yRemainders[i]) % mModulus[i];
  }

  mVectorCount++;
  mArithmeticCount += mNumModuli;

  return RNSNumber(remainders, rns);
}


RNSNumber RNS::multRNSNumbers(RNSNumber x, RNSNumber y, RNS *rns) {
  uint32_t *xRemainders = x.getRemainders();
  uint32_t *yRemainders = y.getRemainders();
  uint32_t remainders[mNumModuli];

  if (x.getRNS() != y.getRNS()) {
    std::cout << "Modular arithmetic performed on RNSNumbers that  are not apart of the same RNS! Exiting Program!" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  for (int i = 0; i < mNumModuli; i++) {
    remainders[i] = (xRemainders[i] + yRemainders[i]) % mModulus[i];
  }

  mVectorCount++;
  mArithmeticCount += mNumModuli;

  return RNSNumber(remainders, rns);
}

std::string RNS::convertToString(RNSNumber num) {}

uint32_t RNS::getAlpha(RNSNumber num) {}
