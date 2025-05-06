#include <iostream>
#include <vector>

using namespace std;

int main() {
  size_t n;
  cin >> n;
  vector<size_t> next(n + 1);
  for (size_t i = 1; i <= n; ++i) {
    size_t key_location;
    cin >> key_location;
    next[i] = key_location;
  }

  vector<bool> visited(n + 1, false);
  size_t cycles = 0;

  for (size_t i = 1; i <= n; ++i) {
    if (!visited[i]) {
      size_t current = i;
      vector<bool> inPath(n + 1, false);

      while (true) {
        if (visited[current]) {
          if (inPath[current]) {
            cycles++;
            size_t node = current;
            do {
              visited[node] = true;
              node = next[node];
            } while (node != current);
          }
          break;
        }
        visited[current] = true;
        inPath[current] = true;
        current = next[current];
      }
    }
  }

  cout << cycles << endl;

  return 0;
}