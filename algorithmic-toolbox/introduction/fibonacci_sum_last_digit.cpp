#include <iostream>

using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

uint64_t fibonacci_sum_fast(uint64_t n) {
    n = n % 60;

    if (n <= 1)
        return n;

    uint64_t previous = 0;
    uint64_t current  = 1;
    uint64_t sum = 1;

    for (int i = 0; i < n - 1; ++i) {
        uint64_t tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += (current % 10);
    }

    return sum % 10;
}
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n) << std::endl;
}
