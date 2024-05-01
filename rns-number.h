#ifndef RNS_NUMBER_H
#define RNS_NUMBER_H

#include <cstdint>
#include <vector>

class RNS;
class RNSNumber {

  public:
    RNSNumber(std::vector<uint32_t> remainders, uint32_t n, RNS *rns);
    ~RNSNumber() { m_Remainders.clear(); }

    [[nodiscard]] std::vector<uint32_t> GetRemainders() const { return m_Remainders; }
    [[nodiscard]] RNS *GetRNS() const { return m_RNS; }

  private:
    std::vector<uint32_t> m_Remainders;
    RNS *m_RNS;
};

#endif
