#include "rns-number.h"
#include <cstdint>

RNSNumber::RNSNumber(const uint32_t remainders[], RNS *rns) {
  int n = sizeof(&remainders) / sizeof(remainders[0]); 
  m_RNS = rns;
  m_Remainders = new uint32_t(n);
  
  for (int i = 0; i < n; i++) {
    m_Remainders[i] = remainders[i];
  }
}
