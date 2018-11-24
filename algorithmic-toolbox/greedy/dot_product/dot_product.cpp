#include <algorithm>
#include <iostream>
#include <vector>
#include <stdint.h>

using std::vector;
using namespace std;

typedef vector<int32_t> vec;

int64_t max_dot_product(vec a, vec b) {
  // write your code here
  int64_t result = 0;

  sort(a.begin(),a.end(), greater<int32_t>());
  sort(b.begin(),b.end(), greater<int32_t>());

  int n = a.size();
  for (size_t i = 0; i < n; i++) {
    result += ((int64_t) *(a.begin())) * *(b.begin());
    a.erase(a.begin());
    b.erase(b.begin());
  }

  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vec s1(n), s2(n);

  int32_t tmp;
  for (size_t i = 0; i < n; i++) {
    std::cin >> s1[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> s2[i];
  }

  std::cout << max_dot_product(s1, s2) << std::endl;
}
