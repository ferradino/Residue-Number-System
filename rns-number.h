#ifndef _RNS_NUMBER_H
#define _RNS_NUMBER_H

#include <cstdint>

class RNS;
class RNSNumber {

  public:
    RNSNumber(const uint32_t remainders[], RNS *rns);
    ~RNSNumber() { delete [] m_Remainders; }

    uint32_t *GetRemainders() const { return m_Remainders; }
    RNS *GetRNS() const { return m_RNS; }

  private:
    uint32_t *m_Remainders;
    RNS *m_RNS;
};

#endif
