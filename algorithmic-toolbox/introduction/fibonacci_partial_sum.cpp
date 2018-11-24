#include <iostream>
#include <stdint.h>

using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

uint64_t get_fibonacci_partial_sum_fast(uint64_t m, uint64_t n) {
    n = n % 60;
    m = m % 60;

    if (n <= 1)
        return n;

    uint64_t previous = 0;
    uint64_t current  = 1;

    uint64_t sum = 1;
    for (int i = 0; i < m - 1; ++i) {
        uint64_t tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }
    sum = current;


    for (int i = 0; i < n - m; ++i) {
        uint64_t tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += (current % 10);
    }

    return sum % 10;
}
int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
