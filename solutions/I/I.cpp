#include <cstddef>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  size_t NNN, KKK, PPP;
  cin >> NNN >> KKK >> PPP;

  vector<size_t> requests(PPP);
  for (size_t i = 0; i != PPP; i++) {
    cin >> requests[i];
  }

  vector<size_t> next_use(PPP, PPP);
  unordered_map<size_t, size_t> last_pos;
  for (int i = PPP - 1; i >= 0; --i) {
    if (last_pos.count(requests[i])) {
      next_use[i] = last_pos[requests[i]];
    }
    last_pos[requests[i]] = i;
  }

  unordered_map<size_t, size_t> floor;
  set<pair<size_t, size_t> > ordered;
  size_t operations = 0;

  for (size_t i = 0; i != PPP; ++i) {
    size_t current = requests[i];
    auto it = floor.find(current);

    if (it != floor.end()) {
      ordered.erase(pair<size_t, size_t>(it->second, current));
      it->second = next_use[i];
      ordered.insert(pair<size_t, size_t>(next_use[i], current));
      continue;
    }

    if (floor.size() >= KKK) {
      auto worst = prev(ordered.end());
      floor.erase(worst->second);
      ordered.erase(worst);
    }

    floor[current] = next_use[i];
    ordered.insert(pair<size_t, size_t>(next_use[i], current));
    operations++;
  }
  cout << operations;
}