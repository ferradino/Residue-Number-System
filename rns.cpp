#include "rns.h"

RNS::RNS(uint32_t moduli[], uint32_t modCount) {
  // Get product of Moduli (M)
  
  // Get m-hat values
  
  // Get inverse values

  // Get r inverses
  
}

RNS::~RNS() {
  delete [] mModuli;
  delete [] mHats;
  delete [] mInverses;
  delete [] mRInverses;
}

RNSNumber RNS::createRNSNumber(uint32_t num) {
  RNSNumber number = RNSNumber(num);
  return number;
}

RNSNumber RNS::createRNSNumber(std::string num) {
  RNSNumber number = RNSNumber((uint32_t)stoi(num));
  return number;
}

RNSNumber RNS::addRNSNumbers(RNSNumber left, RNSNumber right) {
  // uint64_t?
  uint32_t num = left.getNum() + right.getNum(); 
  RNSNumber number = RNSNumber(num);
  mVectorCount++;
  return number;
}

RNSNumber RNS::subRNSNumbers(RNSNumber left, RNSNumber right) {
  // uint64_t?
  uint32_t num = left.getNum() - right.getNum(); 
  RNSNumber number = RNSNumber(num);
  mVectorCount++;
  return number;
}


RNSNumber RNS::multRNSNumbers(RNSNumber left, RNSNumber right) {
  // uint64_t?
  uint32_t num = left.getNum() * right.getNum(); 
  RNSNumber number = RNSNumber(num);
  mVectorCount++;
  return number;
}

std::string RNS::convertToString(RNSNumber num) {}

uint32_t RNS::getAlpha(RNSNumber num) {}
