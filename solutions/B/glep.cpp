#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::stack;
using std::string;
using std::vector;

const int CASE_SHIFT = 32;

struct pairs {
  char symbol;
  size_t position;
};

void catch_animals(string line) {
  if (line.size() % 2 == 1) {
    cout << "Impossible\n";
    return;
  }

  stack<pairs> processing_stack;
  vector<size_t> answers(line.size() / 2);
  size_t index_trap = 0;
  size_t index_animal = 0;

  for (char current : line) {
    bool is_trap = isupper(current);
    size_t current_index = is_trap ? index_trap : index_animal;

    if (!processing_stack.empty()) {
      pairs top = processing_stack.top();
      if (abs(current - top.symbol) == CASE_SHIFT) {
        if (is_trap) {
          answers[current_index] = top.position + 1;
        } else {
          answers[top.position] = current_index + 1;
        }
        processing_stack.pop();
        is_trap ? index_trap++ : index_animal++;
        continue;
      }
    }
    pairs pair;
    pair.position = current_index;
    pair.symbol = current;
    processing_stack.push(pair);
    is_trap ? index_trap++ : index_animal++;
  }

  if (processing_stack.empty()) {
    cout << "Possible\n";
    for (size_t ans : answers) {
      cout << ans << " ";
    }
  } else {
    cout << "Impossible\n";
  }
}
string read_line() {
  string line;
  cin >> line;
  return line;
}

int main() {
  catch_animals(read_line());
  return 0;
}
