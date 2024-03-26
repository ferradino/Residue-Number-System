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
    tNew = r - q * tNew;
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

RNS::RNS(uint32_t moduli[], uint32_t modCount) {
  m_Modulus = new uint32_t(modCount);
  m_MHat = new uint32_t(modCount);
  m_MHatInverse = new uint32_t(modCount);
  m_RInverse = new uint32_t(modCount);

  m_NumModuli = modCount; 

  for (int i = 0; i < m_NumModuli; i++) {
    m_Modulus[i] = moduli[i];
    m_M *= moduli[i];
  }
  
  for (int j = 0; j < m_NumModuli; j++) {
    m_MHat[j] = m_M / m_Modulus[j];
  }

  for (int k = 0; k < m_NumModuli; k++) {
    m_MHatInverse[k] = findInverse(m_MHat[k], m_Modulus[k]);
    m_RInverse[k] = findInverse(m_Modulus[0], m_Modulus[k]);
  }

}

RNS::~RNS() {
  delete [] m_Modulus;
  delete [] m_MHat;
  delete [] m_MHatInverse;
  delete [] m_RInverse;

  for(auto number : m_pRNSNumber) {
    delete number;
  }

  m_pRNSNumber.clear();
}

RNSNumber RNS::CreateRNSNumber(uint32_t num) {
  uint32_t remainders[m_NumModuli];

  for (int i = 0; i < m_NumModuli; i++) {
    remainders[i] = num % m_Modulus[i];
  }
 
  RNSNumber *number = new RNSNumber(remainders, this);
  m_pRNSNumber.push_back(number);
  return *number;
}

RNSNumber RNS::CreateRNSNumber(std::string num) {
  uint32_t remainders[m_NumModuli];

  for (int i = 0; i < m_NumModuli; i++) {
    remainders[i] = uint32_t(stoi(num)) % m_Modulus[i];
  }
 
  RNSNumber *number = new RNSNumber(remainders, this);
  m_pRNSNumber.push_back(number);
  return *number;
}

RNSNumber RNS::AddRNSNumbers(RNSNumber lhs, RNSNumber rhs) {
  uint32_t 
    *x = lhs.GetRemainders(),
    *y = rhs.GetRemainders(),
    a[m_NumModuli];
  uint64_t tmp;

  if (lhs.GetRNS() != rhs.GetRNS()) {
    std::cout << "Modular arithmetic performed on RNSNumbers that are not apart of the same RNS! Exiting Program!" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  for (int i = 0; i < m_NumModuli; i++) {
    tmp = (x[i] + y[i]) % m_Modulus[i];
    a[i] = uint32_t(tmp);
  }

  m_VectorCount++;
  m_ArithmeticCount += m_NumModuli;


  RNSNumber *number = new RNSNumber(a, this);
  m_pRNSNumber.push_back(number);
  return *number;
}

RNSNumber RNS::SubRNSNumbers(RNSNumber lhs, RNSNumber rhs) {
  uint32_t 
    *x = lhs.GetRemainders(), 
    *y = rhs.GetRemainders(), 
    b[m_NumModuli];
  uint64_t tmp;
  
  if (lhs.GetRNS() != rhs.GetRNS()) {
    std::cout << "Modular arithmetic performed on RNSNumbers that are not apart of the same RNS! Exiting Program!" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  for (int i = 0; i < m_NumModuli; i++) {
    tmp = (x[i] - y[i]) % m_Modulus[i];
    b[i] = uint32_t(tmp);
  }

  m_VectorCount++;
  m_ArithmeticCount += m_NumModuli;

  RNSNumber *number = new RNSNumber(b, this);
  m_pRNSNumber.push_back(number);
  return *number;
}


RNSNumber RNS::MultRNSNumbers(RNSNumber lhs, RNSNumber rhs) {
  uint32_t 
    *x = lhs.GetRemainders(),
    *y = rhs.GetRemainders(),
    c[m_NumModuli];
  uint64_t tmp;

  if (lhs.GetRNS() != rhs.GetRNS()) {
    std::cout << "Modular arithmetic performed on RNSNumbers that are not apart of the same RNS! Exiting Program!" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  for (int i = 0; i < m_NumModuli; i++) {
    tmp = (x[i] * y[i]) % m_Modulus[i];
    c[i] = uint32_t(tmp);
  }

  m_VectorCount++;
  m_ArithmeticCount += m_NumModuli;

  RNSNumber *number = new RNSNumber(c, this);
  m_pRNSNumber.push_back(number);
  return *number;
}

// TODO: Implement this
// std::string RNS::ConvertToString(RNSNumber rnsNumber) {}

uint32_t RNS::ComputeAlpha(RNSNumber rnsNumber) {
  uint32_t 
    *a = rnsNumber.GetRemainders(),
    alpha, f;
  uint64_t 
    sum = 0;

  if (rnsNumber.GetRNS() != this) {
    std::cout << "Cannot compute alpha for a RNSNumber of a different RNS! Exiting Program!" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  for (int i = 0; i < m_NumModuli; i++) {
    sum += std::floor((a[i] * m_MHatInverse[i]) << 32 / m_Modulus[i]);
  }

  alpha = sum >> 32;
  f = sum & 0x00000000ffffffff;

  if (f >= 0xffffffff - m_NumModuli + 1) {
    return -1;
  }
    
  return alpha;
}
