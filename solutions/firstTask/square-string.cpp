#include <iostream>
using namespace std;

bool countLine(string line) {
  if (line.length() % 2 != 0) {
    return false;
  }
  int mid = line.length() / 2;
  string firstLine = line.substr(0, mid);
  string secondLine = line.substr(mid);

  return firstLine == secondLine;
}

int main() {
  int count;
  cin >> count;

  for (int i = 0; i < count; i++) {
    string line;
    cin >> line;

    if (countLine(line)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
