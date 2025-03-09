#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool is_number(const string& s) {
  if (s.empty()) {
    return false;
  }
  size_t start = (s[0] == '-') ? 1 : 0;
  if (start >= s.size()) {
    return false;
  }
  for (size_t i = start; i < s.size(); ++i) {
    if (!isdigit(s[i])) {
      return false;
    }
  }
  return true;
}

int main() {
  map<string, stack<int> > variables;
  stack<vector<string> > blocks;

  string line;
  while (getline(cin, line)) {
    if (line == "{") {
      blocks.push(vector<string>());
    } else if (line == "}") {
      for (auto& var : blocks.top()) {
        variables[var].pop();
      }
      blocks.pop();
    } else {
      size_t eq_pos = line.find('=');
      string var = line.substr(0, eq_pos);
      string val = line.substr(eq_pos + 1);

      if (variables[var].empty()) {
        variables[var].push(0);
      }

      if (is_number(val)) {
        int num = stoi(val);
        if (!blocks.empty()) {
          blocks.top().push_back(var);
          variables[var].push(num);
        } else {
          variables[var].pop();
          variables[var].push(num);
        }
      } else {
        int src_val = variables[val].empty() ? 0 : variables[val].top();
        cout << src_val << endl;

        if (!blocks.empty()) {
          blocks.top().push_back(var);
          variables[var].push(src_val);
        } else {
          variables[var].pop();
          variables[var].push(src_val);
        }
      }
    }
  }
  return 0;
}