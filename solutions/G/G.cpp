#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct CharRank {
  char symbol;
  int weight;
  int count;
  CharRank(char s, int w, int c) : symbol(s), weight(w), count(c) {
  }
};

bool compare(const CharRank& a, const CharRank& b) {
  return a.weight > b.weight;
}

int main() {
  const size_t alphabet_length = 26;

  string s;
  cin >> s;

  vector<int> cnt(alphabet_length, 0);
  for (char ch : s)
    cnt[ch - 'a']++;

  vector<CharRank> chars;
  for (size_t i = 0; i < alphabet_length; ++i) {
    int w;
    cin >> w;
    chars.emplace_back('a' + i, w, cnt[i]);
  }

  sort(chars.begin(), chars.end(), compare);

  string prefix, suffix, middle;

  for (const auto& entry : chars) {
    char ch = entry.symbol;
    int& freq = cnt[ch - 'a'];
    if (freq >= 2) {
      prefix += ch;
      suffix += ch;
      freq -= 2;
    }
  }
  reverse(suffix.begin(), suffix.end());

  for (char ch : s) {
    if (cnt[ch - 'a'] > 0) {
      middle += ch;
      cnt[ch - 'a']--;
    }
  }

  cout << prefix + middle + suffix;
  return 0;
}