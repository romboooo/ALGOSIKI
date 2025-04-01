using namespace std;
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

vector<string> readLine() {
  vector<string> out;
  string line;

  while (cin >> line) {
    out.push_back(line);
  }
  return out;
}
bool compareString(const string& a, const string& b) {
  return a + b > b + a;
}
void countResult(vector<string> nums) {
  sort(nums.begin(), nums.end(), compareString);
  string out;

  for (const string& str : nums) {
    out += str;
  }
  cout << out;
}
int main() {
  countResult(readLine());
  return 0;
}