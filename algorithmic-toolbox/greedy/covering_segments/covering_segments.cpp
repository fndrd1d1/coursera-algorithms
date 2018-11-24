#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using std::sort;
using std::endl;
using std::cout;

struct Segment {
  int start, end;
};

bool compare (Segment i, Segment j)
{
    return (i.end < j.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  sort(segments.begin(), segments.end(), compare);

  int lastpoint = segments[0].end;
  points.push_back(lastpoint);

  //write your code here
  for (size_t i = 1; i < segments.size(); ++i) {
    if(segments[i].start > lastpoint)
    {
        points.push_back(segments[i].end);
        lastpoint = segments[i].end;
    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
