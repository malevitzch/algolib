template<typename T>
T fast_exp(T a, int power) {
  T result = 1;
  while (power > 0) {
    if (power % 2 == 1) {
      result *= a;
    }
    a *= a;
    power /= 2;
  }
  return result;
}