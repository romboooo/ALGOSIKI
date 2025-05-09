#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> graph(N + 1);
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<int> color(N + 1, -1);
  queue<int> q;

  for (int start = 1; start <= N; ++start) {
    if (color[start] == -1) {
      color[start] = 0;
      q.push(start);

      while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
          if (color[v] == -1) {
            color[v] = color[u] ^ 1;
            q.push(v);
          } else if (color[v] == color[u]) {
            cout << "NO" << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << "YES" << endl;
  return 0;
}