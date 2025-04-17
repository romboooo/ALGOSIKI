#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Segment {
  size_t begin, end;
  bool is_free;
  Segment* prev;
  Segment* next;

  Segment(size_t b, size_t e, bool free)
      : begin(b), end(e), is_free(free), prev(nullptr), next(nullptr) {
  }

  size_t size() const {
    return end - begin + 1;
  }
};

struct CompareBySize {
  bool operator()(const Segment* a, const Segment* b) const {
    if (a->size() != b->size())
      return a->size() > b->size();
    return a->begin < b->begin;
  }
};

set<Segment*, CompareBySize> free_blocks;
vector<Segment*> alloc_table;

void allocate(size_t size_needed, size_t req_id) {
  if (free_blocks.empty()) {
    alloc_table[req_id] = nullptr;
    cout << "-1\n";
    return;
  }

  auto candidate = *free_blocks.begin();
  if (candidate->size() < size_needed) {
    alloc_table[req_id] = nullptr;
    cout << "-1\n";
    return;
  }

  free_blocks.erase(candidate);
  Segment* new_alloc = new Segment(candidate->begin, candidate->begin + size_needed - 1, false);
  new_alloc->prev = candidate->prev;
  new_alloc->next = nullptr;

  if (candidate->size() > size_needed) {
    Segment* remainder = new Segment(candidate->begin + size_needed, candidate->end, true);
    remainder->prev = new_alloc;
    remainder->next = candidate->next;

    if (candidate->next) {
      candidate->next->prev = remainder;
    }
    new_alloc->next = remainder;
    free_blocks.insert(remainder);
  } else {
    new_alloc->next = candidate->next;
    if (new_alloc->next) {
      new_alloc->next->prev = new_alloc;
    }
  }

  if (new_alloc->prev) {
    new_alloc->prev->next = new_alloc;
  }

  delete candidate;
  alloc_table[req_id] = new_alloc;
  cout << new_alloc->begin << "\n";
}

void merge_free(Segment* seg) {
  Segment* curr = seg->prev;
  while (curr && curr->is_free) {
    seg->begin = curr->begin;
    free_blocks.erase(curr);
    Segment* to_delete = curr;
    curr = curr->prev;
    if (to_delete->prev) {
      to_delete->prev->next = seg;
    }
    seg->prev = to_delete->prev;
    delete to_delete;
  }

  curr = seg->next;
  while (curr && curr->is_free) {
    seg->end = curr->end;
    free_blocks.erase(curr);
    Segment* to_delete = curr;
    curr = curr->next;
    if (to_delete->next) {
      to_delete->next->prev = seg;
    }
    seg->next = to_delete->next;
    delete to_delete;
  }
}

void free_request(int req_num) {
  if (req_num < 1 || req_num >= (int)alloc_table.size() || !alloc_table[req_num]) {
    return;
  }

  Segment* target = alloc_table[req_num];
  if (target->is_free)
    return;

  target->is_free = true;
  alloc_table[req_num] = nullptr;

  merge_free(target);
  free_blocks.insert(target);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t N, M;
  cin >> N >> M;

  alloc_table.resize(M + 1, nullptr);
  free_blocks.insert(new Segment(1, N, true));

  for (size_t i = 1; i <= M; ++i) {
    int val;
    cin >> val;
    if (val > 0) {
      allocate(val, i);
    } else {
      free_request(-val);
    }
  }

  for (auto seg : free_blocks)
    delete seg;
  for (auto seg : alloc_table)
    if (seg)
      delete seg;

  return 0;
}