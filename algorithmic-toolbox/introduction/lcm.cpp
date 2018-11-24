#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b) {
    int tmpA = a;
    int tmpB = 0;
    int current_gcd = b;

    while(current_gcd != 0)
    {
        tmpB = tmpA % current_gcd;
        tmpA = current_gcd;
        current_gcd = tmpB;
    }

    return ((long long)a*b) / ((long long) tmpA);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
