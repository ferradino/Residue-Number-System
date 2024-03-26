#ifndef _RNS_H
#define _RNS_H

#include "rns-number.h"
#include <cstdint>
#include <string>
#include <vector>

class RNS {

  public:
    RNS(uint32_t moduli[], uint32_t modCount);
    ~RNS();

    RNSNumber CreateRNSNumber(uint32_t num);
    RNSNumber CreateRNSNumber(std::string num);
    RNSNumber AddRNSNumbers(RNSNumber lhs, RNSNumber rhs);
    RNSNumber SubRNSNumbers(RNSNumber lhs, RNSNumber rhs);
    RNSNumber MultRNSNumbers(RNSNumber lhs, RNSNumber rhs);

    int32_t GetVectorCount() const { return m_VectorCount; }
    int32_t GetArithmeticCount() const { return m_ArithmeticCount; }

    std::string ConvertToString(RNSNumber rnsNumber);

    uint32_t ComputeAlpha(RNSNumber rnsNumber);
    
  private:
    int32_t m_NumModuli;
    int32_t m_VectorCount;
    int32_t m_ArithmeticCount;

    uint32_t m_M;
    uint32_t *m_Modulus;
    uint32_t *m_MHat;
    uint32_t *m_RInverse;
    uint32_t *m_MHatInverse;

    std::vector<RNSNumber*> m_pRNSNumber;
};

#endif
