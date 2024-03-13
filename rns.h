#ifndef _RNS_H
#define _RNS_H

#include "rns-number.h"
#include <cstdint>
#include <string>

class RNS {

  public:
    RNS(uint32_t moduli[], uint32_t modCount);
    ~RNS();

    RNSNumber createRNSNumber(uint32_t num);
    RNSNumber createRNSNumber(std::string num);
    RNSNumber addRNSNumbers(RNSNumber left, RNSNumber right);
    RNSNumber subRNSNumbers(RNSNumber left, RNSNumber right);
    RNSNumber multRNSNumbers(RNSNumber left, RNSNumber right);

    int32_t getVectorCount() { return mVectorCount; }
    int32_t getArithmeticCount() { return mArithmeticCount; }

    std::string convertToString(RNSNumber num);

    uint32_t getAlpha(RNSNumber num);
    
  private:
    int32_t mNumModuli;
    int32_t mVectorCount;
    int32_t mArithmeticCount;
    uint32_t *mModuli;
    uint32_t *mHats;
    uint32_t *mInverses;
    uint32_t *mRInverses;
};

#endif
