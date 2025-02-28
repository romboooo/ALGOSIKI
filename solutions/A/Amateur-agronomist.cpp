#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

void countRow(vector<size_t> flowers, size_t count) {
  size_t tailRowIndex = 0;
  size_t maxHeadRowIndex = 0;
  size_t maxTailRowIndex = 0;

  for (size_t i = 1; i != count; i++) {
    if (i >= 2 && flowers[i] == flowers[i - 1] && flowers[i - 1] == flowers[i - 2]) {
      tailRowIndex = i - 1;
    }

    if (i - tailRowIndex > maxHeadRowIndex - maxTailRowIndex) {
      maxHeadRowIndex = i;
      maxTailRowIndex = tailRowIndex;
    }
  }

  cout << maxTailRowIndex + 1 << " " << maxHeadRowIndex + 1;
}

int main() {
  size_t count;
  cin >> count;
  vector<size_t> flowers(count);

  for (size_t i = 0; i != count; i++) {
    cin >> flowers[i];
  }

  countRow(flowers, count);

  return 0;
}