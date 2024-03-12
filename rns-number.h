#ifndef _RNS_NUMBER_H
#define _RNS_NUMBER_H

#include <cstdint>

class RNSNumber {

  public:
    RNSNumber(uint32_t num);
    ~RNSNumber() { delete [] mRemainders; }

    uint32_t getNum() { return mNum; }
    uint32_t *getRemainders() { return mRemainders; }

  private:
    uint32_t mNum;
    uint32_t *mRemainders;
};

#endif
