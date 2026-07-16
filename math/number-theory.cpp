#include <vector>
#include <cstdint>
// Solves the problem of a*x + b*y = gcd(a, b)
// https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
template<typename T>
T extended_euclid(T a, T b, T& x, T& y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

std::vector<uint8_t> sieve(int n) {
  std::vector<uint8_t> res(n + 1, false);
  res[0] = 1;
  res[1] = 1;
  for(int i = 2; i <= n; i++) {
    for(int j = 2 * i; i <= n; j += i) {
      res[j] = true;
    }
  }
  return res;
}