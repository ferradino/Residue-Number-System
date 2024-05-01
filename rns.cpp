#include "rns.h"
#include <iostream>

uint32_t findInverse(int64_t a, int64_t n) {
  int64_t
    r = n, rNew = a,
    t = 0, tNew = 1,
    q, tmp;

  while (rNew != 0) {
    q = r / rNew;

    tmp = rNew;
    rNew = r - q * rNew;
    r = tmp;

    tmp = tNew;
    tNew = t - q * tNew;
    t = tmp;
  }

  if (r > 1) {
    std::cout << "Mod inverse failed" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  if (t < 0) {
    t += n;
  }

  return uint32_t(t);
}

RNS::RNS(const uint32_t moduli[], uint32_t modCount) {
  m_Modulus.resize(modCount);
  m_MHat.resize(modCount);
  m_MHatInverse.resize(modCount);
  m_RInverse.resize(modCount);

  m_NumModuli = modCount;
  m_M = 1;

  for (uint32_t i = 0; i < m_NumModuli; i++) {
    m_Modulus[i] = moduli[i];
    m_M *= moduli[i];
  }

  for (uint32_t j = 0; j < m_NumModuli; j++) {
    m_MHat[j] = m_M / m_Modulus[j];
  }

  for (uint32_t k = 0; k < m_NumModuli; k++) {
    m_MHatInverse[k] = findInverse(m_MHat[k], m_Modulus[k]);
    if (k > 0) {
      m_RInverse[k] = findInverse(m_Modulus[0], m_Modulus[k]);
    }
  }

}

RNS::~RNS() {
  m_Modulus.clear();
  m_MHat.clear();
  m_MHatInverse.clear();
  m_RInverse.clear();

  for(auto number : m_pRNSNumber) {
    delete number;
  }

  m_pRNSNumber.clear();
}

RNSNumber RNS::CreateRNSNumber(uint32_t num) {
  std::vector<uint32_t> remainders(m_NumModuli);

  for (uint32_t i = 0; i < m_NumModuli; i++) {
    remainders[i] = num % m_Modulus[i];
  }
 
  auto *number = new RNSNumber(remainders, m_NumModuli, this);
  m_pRNSNumber.push_back(number);
  return *number;
}

RNSNumber RNS::CreateRNSNumber(const std::string& num) {
  std::vector<uint32_t> remainders(m_NumModuli);

  for (uint32_t i = 0; i < m_NumModuli; i++) {
    remainders[i] = uint32_t(stoi(num)) % m_Modulus[i];
  }
 
  auto *number = new RNSNumber(remainders, m_NumModuli, this);
  m_pRNSNumber.push_back(number);
  return *number;
}

RNSNumber RNS::AddRNSNumbers(const RNSNumber& lhs, const RNSNumber& rhs) {
  std::vector<uint32_t>
    x = lhs.GetRemainders(),
    y = rhs.GetRemainders(),
    a(m_NumModuli);

  uint64_t tmp;

  if (lhs.GetRNS() != rhs.GetRNS()) {
    std::cout << "Modular arithmetic performed on RNSNumbers that are not apart of the same RNS! Exiting Program!" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  for (uint32_t i = 0; i < m_NumModuli; i++) {
    tmp = (x[i] + y[i]) % m_Modulus[i];
    a[i] = uint32_t(tmp);
  }

  m_VectorCount++;
  m_ArithmeticCount += m_NumModuli;


  auto *number = new RNSNumber(a, m_NumModuli, this);
  m_pRNSNumber.push_back(number);
  return *number;
}

RNSNumber RNS::SubRNSNumbers(const RNSNumber& lhs, const RNSNumber& rhs) {
  std::vector<uint32_t>
    x = lhs.GetRemainders(),
    y = rhs.GetRemainders(),
    b(m_NumModuli);

  uint64_t tmp;
  
  if (lhs.GetRNS() != rhs.GetRNS()) {
    std::cout << "Modular arithmetic performed on RNSNumbers that are not apart of the same RNS! Exiting Program!" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  for (uint32_t i = 0; i < m_NumModuli; i++) {
    tmp = (x[i] - y[i]) % m_Modulus[i];
    b[i] = uint32_t(tmp);
  }

  m_VectorCount++;
  m_ArithmeticCount += m_NumModuli;

  auto *number = new RNSNumber(b, m_NumModuli, this);
  m_pRNSNumber.push_back(number);
  return *number;
}


RNSNumber RNS::MultRNSNumbers(const RNSNumber& lhs, const RNSNumber& rhs) {
  std::vector<uint32_t>
    x = lhs.GetRemainders(),
    y = rhs.GetRemainders(),
    c(m_NumModuli);

  uint64_t tmp;

  if (lhs.GetRNS() != rhs.GetRNS()) {
    std::cout << "Modular arithmetic performed on RNSNumbers that are not apart of the same RNS! Exiting Program!" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  for (uint32_t i = 0; i < m_NumModuli; i++) {
    tmp = (x[i] * y[i]) % m_Modulus[i];
    c[i] = uint32_t(tmp);
  }

  m_VectorCount++;
  m_ArithmeticCount += m_NumModuli;

  auto *number = new RNSNumber(c, m_NumModuli, this);
  m_pRNSNumber.push_back(number);
  return *number;
}

// std::string RNS::ConvertToString(RNSNumber rnsNumber) { return "";}

uint32_t RNS::ComputeAlpha(const RNSNumber& rnsNumber) {
  std::vector<uint32_t>
    a = rnsNumber.GetRemainders();
  uint32_t
    alpha, f;
  uint64_t 
    sum = 0;

  if (rnsNumber.GetRNS() != this) {
    std::cout << "Cannot compute alpha for a RNSNumber of a different RNS! Exiting Program!" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  for (uint32_t i = 0; i < m_NumModuli; i++) {
    sum += std::floor((a[i] * m_MHatInverse[i]) << 32 / m_Modulus[i]);
  }

  alpha = sum >> 32;
  f = sum & 0x00000000ffffffff;

  if (f >= 0xffffffff - m_NumModuli + 1) {
    return -1;
  }
    
  return alpha;
}
