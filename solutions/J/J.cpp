#include <cstddef>
#include <deque>
#include <iostream>
using namespace std;

int main() {
  size_t deque_lenght;
  cin >> deque_lenght;

  deque<size_t> left_deque;
  deque<size_t> right_deque;

  for (size_t i = 0; i != deque_lenght; ++i) {
    char sign;
    cin >> sign;

    if (sign == '+') {
      size_t goblin_number;
      cin >> goblin_number;
      right_deque.push_back(goblin_number);
    } else if (sign == '*') {
      size_t goblin_number;
      cin >> goblin_number;
      if (left_deque.size() > right_deque.size()) {
        right_deque.push_front(goblin_number);
      } else {
        left_deque.push_back(goblin_number);
      }
    } else if (sign == '-') {
      if (left_deque.empty()) {
        while (!right_deque.empty()) {
          left_deque.push_back(right_deque.front());
          right_deque.pop_front();
        }
      }
      cout << left_deque.front() << '\n';
      left_deque.pop_front();
    }

    if (left_deque.size() < right_deque.size()) {
      left_deque.push_back(right_deque.front());
      right_deque.pop_front();
    }
  }

  return 0;
}