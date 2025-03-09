#include <algorithm>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::min;
using namespace std;

size_t bacteria_count() {
  long long aaa, bbb, ccc, ddd;
  size_t kkk;
  cin >> aaa >> bbb >> ccc >> ddd >> kkk;
  long long bacterias_after_experiment;
  long long bacterias_after_incubator;
  long long current_a = aaa;
  vector<long long> history;

  for (size_t i = 1; i <= kkk; i++) {
    vector<long long>::iterator iterator = find(history.begin(), history.end(), current_a);
    if (iterator != history.end()) {
      size_t cycle_length = history.end() - iterator;
      long long remaining_days = kkk - i;
      current_a = iterator[(remaining_days) % cycle_length];
      break;
    }
    history.push_back(current_a);

    bacterias_after_incubator = current_a * bbb;

    if (ccc > bacterias_after_incubator) {
      return 0;
    }

    bacterias_after_experiment = bacterias_after_incubator - ccc;
    current_a = min(bacterias_after_experiment, ddd);

    if (current_a == history.back()) {
      break;
    }
  }
  return current_a;
}

int main() {
  cout << bacteria_count();
  return 0;
}