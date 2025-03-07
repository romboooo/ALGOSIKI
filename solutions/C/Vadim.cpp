#include <cstddef>
#include <iostream>
using std::cin;
using std::cout;
using std::min;

size_t bacteria_count() {
  long long aaa, bbb, ccc, ddd;
  size_t kkk;
  cin >> aaa >> bbb >> ccc >> ddd >> kkk;
  long long bacterias_after_experiment;
  long long bacterias_after_incubator;
  long long current_a = aaa;

  for (size_t i = 1; i <= kkk; i++) {
    bacterias_after_incubator = current_a * bbb;

    if (ccc > bacterias_after_incubator) {
      return 0;
    }

    bacterias_after_experiment = bacterias_after_incubator - ccc;
    current_a = min(bacterias_after_experiment, ddd);
  }
  return current_a;
}

int main() {
  cout << bacteria_count();
  return 0;
}