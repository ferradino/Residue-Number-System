#ifndef RNS_H
#define RNS_H

#include "rns-number.h"
#include <cstdint>
#include <string>
#include <vector>

class RNS {

  public:
    RNS(const uint32_t moduli[], uint32_t modCount);
    ~RNS();

    RNSNumber CreateRNSNumber(uint32_t num);
    RNSNumber CreateRNSNumber(const std::string& num);
    RNSNumber AddRNSNumbers(const RNSNumber& lhs, const RNSNumber& rhs);
    RNSNumber SubRNSNumbers(const RNSNumber& lhs, const RNSNumber& rhs);
    RNSNumber MultRNSNumbers(const RNSNumber& lhs, const RNSNumber& rhs);

    [[nodiscard]] uint32_t GetVectorCount() const { return m_VectorCount; }
    [[nodiscard]] uint32_t GetArithmeticCount() const { return m_ArithmeticCount; }

    // std::string ConvertToString(RNSNumber rnsNumber);

    uint32_t ComputeAlpha(const RNSNumber& rnsNumber);
    
  private:
    uint32_t m_VectorCount = 0;
    uint32_t m_ArithmeticCount = 0;

    uint32_t m_NumModuli;
    std::vector<uint32_t> m_Modulus;

    uint32_t m_M;

    std::vector<uint32_t> m_MHat;
    std::vector<uint32_t> m_RInverse;
    std::vector<uint32_t> m_MHatInverse;

    std::vector<RNSNumber*> m_pRNSNumber;
};

#endif
