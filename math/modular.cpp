#include <iostream>
#include <vector>
#include "fastexpo.cpp"

template <typename T>
struct modular {
  template<T MOD>
  struct mod {
    T val;

    mod<MOD> operator-() const {
      return mod<MOD>(MOD - val);
    }

    mod<MOD> operator+(const mod<MOD> m) const {
      return (val + m.val) % MOD;
    }
    mod<MOD> operator-(const mod<MOD> m) const {
      return (*this) + (-m);
    }
    mod<MOD> operator*(const mod<MOD> m) const {
      return mod<MOD>((val * m.val) % MOD);
    }
    mod<MOD> inverse() const {
      if(val == 0) throw std::runtime_error("Trying to compute inverse of 0");
      return fast_exp<mod<MOD>>(*this, MOD - 2);
    }
    mod<MOD> operator/(const mod<MOD> m) const {
      return (*this) * m.inverse();
    }
    static mod<MOD> factorial(size_t n) {
      static int last = 0;
      static std::vector<mod<MOD>> fact = {1};
      while(last < n) fact.push_back(fact.back() * mod<MOD>(++last));
      return fact[n];
    }

    mod(T val) : val(val % MOD) {}
    friend std::istream& operator>>(std::istream& s, const mod<MOD>& x) {
      s >> x.val; return s;
    }
    friend std::ostream& operator<<(std::ostream& s, const mod<MOD>& x) {
      s << x.val; return s;
    }
  };
};
template <typename T, T MOD>
typename modular<T>::template mod<MOD> operator+(typename modular<T>::template mod<MOD> a, T b) {
  return a + typename modular<T>::template mod<MOD>(b);
}

template <typename T, T MOD>
typename modular<T>::template mod<MOD> operator+(T a, typename modular<T>::template mod<MOD> b) {
  return typename modular<T>::template mod<MOD>(a) + b;
}

// This is how you generate a specific type, first specify
// the "carrier" type, then the modulus. For certain things to work,
// the carrier type should accept 0 and 1.
using ll97 = modular<long long>::mod<(long long)(1e9 + 7)>;
using ll99 = modular<long long>::mod<(long long)(1e9 + 9)>;