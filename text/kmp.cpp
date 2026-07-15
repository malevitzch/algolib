#include <string>
#include <vector>

// https://cp-algorithms.com/string/prefix-function.html
std::vector<int> kmp(std::string text) {
  std::vector<int> res(text.size());
  for(int i = 1; i < text.size(); i++) {
    int j = res[i-1];
    while(j > 0 && text[i] != text[j]) j = res[j-1];
    if(text[i] == text[j]) j++;
    res[i] = j;
  }
  return res;
}