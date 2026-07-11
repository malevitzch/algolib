#include "modular.cpp"
#include <vector>

template<typename M>
M factorial(size_t n) {
  if(n >= M::modulus) return 0;
  static int last = 0;
  static std::vector<M> fact = {1};
  while(last < n) fact.push_back(fact.back() * M(++last));
  return fact[n];
}

template<typename M>
M binomial(size_t n, size_t k) {
  if(k > n) return 0;
  return factorial<M>(n) / (factorial<M>(k) * factorial<M>(n - k));
}