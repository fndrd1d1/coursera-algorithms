#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdint.h>

using namespace std;

uint64_t get_fibonacci_huge_naive(uint64_t n, uint64_t m) {
    if (n <= 1)
        return n;

    uint64_t previous = 0;
    uint64_t current  = 1;

    for (uint64_t i = 0; i < n - 1; ++i) {
        uint64_t tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) %m ;
    }

    return current % m;
}

int getRepetition(uint64_t n, uint64_t m)
{
    uint64_t previous = 0;
    uint64_t current  = 1;

    int ret = 0;

    if(m > n)
    {
        return 0;
    }

    while(1)
    {
        uint64_t tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;

        ret++;

        if((current == 1) && (previous == 0))
        {
            break;
        }
    }

    return ret;
}
uint64_t get_fibonacci_huge_fast(uint64_t n, uint64_t m) {
    if (n <= 1)
        return n;

    int count = 0;
    if (m < n)
    {
        int k =  getRepetition(n,m);
        if(k < n)
        {
            count = (n % k) ;
        }
        else
        {
            count = n;
        }
    }
    else
    {
        count = n ;
    }

    uint64_t previous = 0;
    uint64_t current  = 1;

    for (uint64_t i = 0; i < count - 1 ; ++i) {
        uint64_t tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }

    if(count == 0)
    {
        current = 0;
    }

    return current % m;
}

int main() {
    uint64_t n, m;
    int x;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << "\n";
    /*
    while(1)
    {
        std::cin >> n >> m;
        std::cout << getRepetition(n, m)  << '\n';
    }

    */
    /*
    while(1)
    {
        n = rand() % 100 + 1 ;
        m = rand() % 100 + 2;

        std::cout << n << " " << m << std::endl;

        int n1 = get_fibonacci_huge_fast(n, m);
        int n2 = get_fibonacci_huge_naive(n, m);

        std::cout << "naive: " << n2 << std::endl;
        std::cout << "fast: " << n1 << std::endl;
        if(n1 != n2) break;
    }


    std::cout << "(15, 1000)" << endl;
    std::cout << "fib:" << get_fibonacci_huge_fast(15, 1000) << endl;// << '\n';
    std::cout << "fib:" << get_fibonacci_huge_naive(15, 1000) << endl;// << '\n';
    std::cout << "(10, 1000)" << endl;
    std::cout << "fib:" << get_fibonacci_huge_fast(10, 1000) << endl;// << '\n';
    std::cout << "(2015, 3)" << endl;
    std::cout << "fib:" << get_fibonacci_huge_fast(2015, 3) << endl;// << '\n';
    std::cout << "(1, 239)" << endl;
    std::cout << "fib:" << get_fibonacci_huge_fast(1, 239) << endl;// << '\n';
    std::cout << "(239, 1000)" << endl;
    std::cout << "fib:" << get_fibonacci_huge_fast(239, 1000) << endl;// << '\n';
    std::cout << "(2816213588,30524)" << endl;
    std::cout << "fib:" << get_fibonacci_huge_fast(2816213588,30524) << endl;// << '\n';
    std::cout << "(99999999999999999,2)" << endl;
    std::cout << "fib:" << get_fibonacci_huge_fast(99999999999999999,2) << endl;// << '\n';

    */
    /*
    for(int i = 0; i < 10; ++i)
    {
        std::cout << get_fibonacci_huge_naive(i, 3) << " ";// << '\n';
    }

    std::cout << std::endl;
    std::cout << getRepetition(10, 3)  << '\n';
    std::cout << "fib:" << get_fibonacci_huge_fast(10, 3) << endl;

    */
}
