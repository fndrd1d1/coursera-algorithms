#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave + 1, right);

  merge(a,b, left, ave, ave+1, right);

  return number_of_inversions;
}

long long merge(vector<int> &a,
        vector<int> &b,
        int aleft,
        int aright,
        int bleft,
        int bright)
{
    int ai = aleft;
    int bi = bright;
    while(!a.empty() && !b.empty())
    {
        int ael = a.front();
        int bel = b.front();

        if(ael <= bel)
        {
           b.push_back(ael);
        }
        else
        {
           b.push_back(bel);
        }
    }
    while(!a.empty())
    {
        b.push_back(a.front());
    }
    while(!b.empty())
    {
        b.push_back(b.front());
    }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
