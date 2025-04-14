#include <cstddef>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  size_t NNN, window_len;
  cin >> NNN >> window_len;

  cin >> ws;

  string nums;
  getline(cin, nums);

  istringstream iss(nums);
  vector<int> numbers;
  int num;

  while (iss >> num) {
    numbers.push_back(num);
  }

  deque<size_t> window;

  for (size_t i = 0; i != NNN; ++i) {
    while (!window.empty() && numbers[i] <= numbers[window.back()]) {
      window.pop_back();
    }
    window.push_back(i);
    while (window.front() + window_len <= i) {
      window.pop_front();
    }
    if (i >= window_len - 1) {
      cout << numbers[window.front()] << " ";
    }
  }

  return 0;
}