#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int get_count(vector<int> &a, int left, int right, int element)
{
    int count = 0;
    for(int i = left; i<=right; ++i)
    {
        if(a[i] == element) count++;
    }
    return count;
}
int get_majority_element(vector<int> &a, int left, int right) {
  if (left > right) return -1;
  if (left == right) return a[left];

  int middle = (left + right)/2;

  int m1 = get_majority_element(a, left, middle);
  int m2 = get_majority_element(a, middle+1, right);

  if(m1 != -1 && m2 == -1)
  {
    int count1 = get_count(a, left, right, m1);
    if(count1 > ((right - left + 1) /2))        return m1;
    else                                        return -1;
  }
  else if(m1 == -1 && m2 != -1)
  {
    int count2 = get_count(a, left, right, m2);
    if(count2 > ((right - left + 1) /2))        return m2;
    else                                        return -1;
  }
  else if(m1 != -1 && m2 != -1)
  {
    int count1 = get_count(a, left, right, m1);
    int count2 = get_count(a, left, right, m2);

    if(count1 > ((right - left + 1) /2))        return m1;
    else if(count2 > ((right - left + 1) /2))   return m2;
    else                                        return -1;
  }
  else
  {
    return -1;
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
}
