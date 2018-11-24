#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::vector;
using std::sort;
using std::cout;
using std::endl;
using std::pair;

bool compare (pair<double, double> i, pair<double, double> j)
{
    return ((i.first / i.second)
            >
            (j.first / j.second));
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  vector<pair< double,double> > sortedvw(weights.size());

  // O(n)
  for(int i = 0; i < weights.size(); ++i)
  {
    sortedvw[i] = std::make_pair(
            static_cast<double>(values[i]),
            static_cast<double>(weights[i]));
  }

  // O(nlogn)
  sort(sortedvw.begin(), sortedvw.end(), compare);

  // O(n)
  int i = 0;
  while(capacity > 0 && i < sortedvw.size())
  {
    double currentValue = sortedvw[i].first;
    double currentWeight = sortedvw[i].second;

    if(capacity >= currentWeight)
    {
        value += currentValue;
        capacity -= currentWeight;
    }
    else
    {
        value += currentValue/currentWeight
                 * capacity;
        capacity -= capacity;
    }
    i++;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
