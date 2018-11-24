#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stdint.h>

using std::vector;
using std::min;
using std::cout;
using std::endl;

vector<int> incorrect(int n) {
    std::vector<int> sequence;
    while (n >= 1) {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

void reset_values(uint32_t &a, uint32_t &b, uint32_t &c)
{
    a = UINT32_MAX;
    b = UINT32_MAX;
    c = UINT32_MAX;
}

vector<uint32_t> optimal_sequence(
        uint32_t n)
{
    std::vector<uint32_t> seq(n+1);
    std::vector<uint32_t> res;

    uint32_t i = 1;
    uint32_t a, b, c;
    uint32_t minvalue;

    //seq[0] = 0;
    //seq[1] = 0;

    // generate c(n)
    // O(n)
    for(;i<n+1;++i)
    {
        seq[i] = seq[i-1] + 1;
        if(i%2 == 0) seq[i] = min(seq[i/2] + 1, seq[i]);
        if(i%3 == 0) seq[i] = min(seq[i/3] + 1, seq[i]);

        /*
         * sloooow: O(n^2);
        seq[i] = UINT32_MAX;
        for(uint32_t j = 1; j <= i; ++j)
        {
            reset_values(a,b,c);

            if(j%3 == 0)
            {
                a = seq[j/3] + 1;
            }

            if(j%2 == 0)
            {
                b = seq[j/2] + 1;
            }

            c = seq[j-1] + 1;

            minvalue = min(a,b);
            minvalue = min(minvalue, c);

            if(minvalue < seq[j])
            {
                seq[j] = minvalue;
            }
        }
        */
    }

    // backtracking intermediate results
    uint32_t bt = n;
    res.push_back(bt);

    while(bt > 1)
    {
        if(bt%3 == 0 && seq[bt/3] == seq[bt] - 1) bt = bt/3;
        else if(bt%2 == 0 && seq[bt/2] == seq[bt] - 1) bt = bt/2;
        else if(seq[bt-1] == seq[bt] - 1) bt--;
        res.push_back(bt);
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    uint32_t n;
    std::cin >> n;
    vector<uint32_t> sequence = optimal_sequence(n);

    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
}
