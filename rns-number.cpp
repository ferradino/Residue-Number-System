#include "rns-number.h"
#include <cstdint>

RNSNumber::RNSNumber(std::vector<uint32_t> remainders, uint32_t n, RNS *rns) {
  m_RNS = rns;
  m_Remainders.resize(n);

  for (uint32_t i = 0; i < n; i++) {
    m_Remainders[i] = remainders[i];
  }
}