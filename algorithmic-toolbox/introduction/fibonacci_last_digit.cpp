#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

uint64_t get_fibonacci_last_digit_naive(uint64_t n) {
    if (n <= 1)
        return n;

    uint64_t previous = 0;
    uint64_t current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        uint64_t tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) %10;
    }

    return current % 10;
}

uint64_t get_fibonacci_last_digit_fast(uint64_t n) {
    if (n <= 1)
        return n;

    n = n % 60;

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

/*
int main() {
    int n;

    while(1)
    {
        n = rand() % 100 + 1 ;
        int c = get_fibonacci_last_digit_fast(n);
        int d = get_fibonacci_last_digit_naive(n);

        if(c!=d)
        {
            std::cout << c << std::endl;
            std::cout << d << std::endl;
        }
    }
}
*/
int main()
{
    int n;
    cin >> n;
    cout << get_fibonacci_last_digit_fast(n) << endl;
    /*
    int count = 0;
    uint64_t sum = 0;
    uint64_t sumold = 0;
    //int c = get_fibonacci_last_digit_naive(n);
    for (int i = 0; i < 100; ++i)
    {
        uint64_t c = (get_fibonacci_last_digit_naive(i));
        sumold = sum;
        sum += c;
        cout << sum % 10 << endl;

        count++;
    }
    */
}
