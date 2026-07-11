#include <iostream>
#include "fastexpo.cpp"

template <typename T, T MOD>
struct mod {
  static const T modulus = MOD;
  using val_type = T;
  T val;

  mod(T val = 0) : val(((val % MOD) + MOD) % MOD) {}

  mod operator-() const {
    return mod(MOD - val);
  }
  mod operator+(const mod m) const {
    return mod(val + m.val);
  }
  mod operator-(const mod m) const {
    return (*this) + (-m);
  }
  mod operator*(const mod m) const {
    return mod(val * m.val);
  }
  mod inverse() const {
    if (val == 0) throw std::runtime_error("Trying to compute inverse of 0");
    return fast_exp<mod>(*this, MOD - 2);
  }
  mod operator/(const mod m) const {
    return (*this) * m.inverse();
  }

  friend std::istream& operator>>(std::istream& s, mod& x) {
    T v; s >> v; x = mod(v); return s;
  }
  friend std::ostream& operator<<(std::ostream& s, const mod& x) {
    s << x.val; return s;
  }
};

template <typename T, T MOD>
mod<T, MOD> operator+(mod<T, MOD> a, T b) {
  return a + mod<T, MOD>(b);
}
template <typename T, T MOD>
mod<T, MOD> operator+(T a, mod<T, MOD> b) {
  return mod<T, MOD>(a) + b;
}

using ll97 = mod<long long, (long long)(1e9 + 7)>;
using ll99 = mod<long long, (long long)(1e9 + 9)>;