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

// https://cp-algorithms.com/algebra/primality_tests.html
using u64 = uint64_t;
using u128 = __uint128_t;
u64 binpower(u64 base, u64 e, u64 mod) {
  u64 result = 1;
  base %= mod;
  while(e) {
    if(e & 1) result = (u128)result * base % mod;
    base = (u128)base * base % mod;
    e >>= 1;
  }
  return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
  u64 x = binpower(a, d, n);
  if(x == 1 || x == n - 1) return false;
  for(int r = 1; r < s; r++) {
    x = (u128)x * x % n;
    if(x == n - 1) return false;
  }
  return true;
};

bool is_prime(u64 n) {
  if(n < 2) return false;
  int r = 0;
  u64 d = n - 1;
  while((d & 1) == 0) {
    d >>= 1;
    r++;
  }

  for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if(n == a) return true;
    if(check_composite(n, a, d, r)) return false;
  }
  return true;
}
