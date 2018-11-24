#include <iostream>
#include <stdint.h>

using namespace std;

int get_change(int m) {
    uint8_t c10 = 0;
    uint8_t c5 = 0;
    uint8_t c1 = 0;


    uint16_t left = m;

    if(left >= 10)
    {
        c10 = left / 10;
        left -= c10 * 10;
    }

    if(left >= 5)
    {
        c5 = left / 5;
        left -= c5 * 5;
    }

    if(left >= 1)
    {
        c1 = left;
    }

    return (c10 + c5 + c1);
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
