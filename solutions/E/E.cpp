#include <iostream>
#include <vector>

using namespace std;

struct CowPlacer {
  size_t cows;
  size_t stalls_count;
  vector<size_t> stalls;

  void readData() {
    cin >> stalls_count >> cows;
    stalls.resize(stalls_count);
    for (size_t i = 0; i < stalls_count; ++i) {
      cin >> stalls[i];
    }
  }

  bool canPlace(size_t d) {
    size_t count = 1;
    size_t last = stalls[0];
    for (size_t i = 1; i < stalls.size(); ++i) {
      if (stalls[i] - last >= d) {
        count++;
        last = stalls[i];
        if (count >= cows) {
          return true;
        }
      }
    }
    return count >= cows;
  }

  int calculateMaxDistance() {
    size_t left = 0;
    size_t right = stalls.back() - stalls[0];
    size_t answer = 0;

    while (left <= right) {
      size_t mid = left + (right - left) / 2;
      if (canPlace(mid)) {
        answer = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return answer;
  }
};

int main() {
  CowPlacer solver;
  solver.readData();
  int result = solver.calculateMaxDistance();
  cout << result;
  return 0;
}