#include <string>
#include <vector>

// https://cp-algorithms.com/string/z-function.html
std::vector<int> z_function(std::string s) {
  std::vector<int> z(s.size());
  int l = 0, r = 0;
  for(int i = 1; i < s.size(); i++) {
    if(i < r) z[i] = std::min(r - i, z[i - 1]);
    while(i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) z[i]++;
    if(i + z[i] > r) l = i, r = i + z[i];
  }
  return z;
}