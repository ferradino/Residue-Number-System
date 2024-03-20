#ifndef _RNS_NUMBER_H
#define _RNS_NUMBER_H

#include <cstdint>

class RNS;
class RNSNumber {

  public:
    RNSNumber(uint32_t remainders[], uint32_t numRemainders, RNS *rns);
    ~RNSNumber() { delete [] mRemainders; }

    uint32_t *getRemainders() { return mRemainders; }

  private:
    uint32_t *mRemainders;
    RNS *mRNS;
};

#endif
