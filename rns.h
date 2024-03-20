#ifndef _RNS_H
#define _RNS_H

#include "rns-number.h"
#include <cstdint>
#include <string>

class RNS {

  public:
    RNS(uint32_t moduli[], uint32_t modCount);
    ~RNS();

    RNSNumber createRNSNumber(uint32_t num, RNS *rns);
    RNSNumber createRNSNumber(std::string num, RNS *rns);
    RNSNumber addRNSNumbers(RNSNumber x, RNSNumber y, RNS *rns);
    RNSNumber subRNSNumbers(RNSNumber x, RNSNumber y, RNS *rns);
    RNSNumber multRNSNumbers(RNSNumber x, RNSNumber y, RNS *rns);

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
