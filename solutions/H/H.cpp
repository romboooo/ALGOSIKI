#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  size_t nnn, kkk;
  cin >> nnn >> kkk;
  vector<size_t> prices(nnn);

  for (size_t i = 0; i < nnn; ++i) {
    cin >> prices[i];
  }
  sort(prices.rbegin(), prices.rend());

  size_t total = 0;
  for (size_t i = 0; i < nnn; ++i) {
    if ((i + 1) % kkk != 0) {
      total += prices[i];
    }
  }

  cout << total;
  return 0;
}