#include <iostream>

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

    mod(T val) : val(val % MOD) {}
    friend std::istream& operator>> (std::istream& s, const mod<MOD>& x) {
      s >> x.val; return s;
    }
    friend std::ostream& operator<< (std::ostream& s, const mod<MOD>& x) {
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

using ll97 = modular<long long>::mod<(long long)(1e9 + 7)>;
using ll99 = modular<long long>::mod<(long long)(1e9 + 9)>;
