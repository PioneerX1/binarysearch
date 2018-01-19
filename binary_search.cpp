#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size();
  if (right == 1 && x != a[0]) { return -1; }

  if (x >= 1) {
    int mid = int(right / 2);

    if (x == a[mid]) {
      return mid;
    } else if (x > a[mid]) {
      vector<int>highsplit(a.begin() + mid, a.end());
      return binary_search(highsplit, x) + mid;
    } else if (x < a[mid]) {
      vector<int>lowsplit(a.begin(), a.begin() + mid);
      return binary_search(lowsplit, x);
    }

  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
//  std::cout << std::endl;
}
