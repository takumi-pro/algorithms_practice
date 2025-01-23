#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n,l;
  cin >> n >> l;

  vector<int> t(n);

  int m = 1000000;
  for (int i=1; i<=n; i++) {
    int taste = l+i-1;
    int a = abs(taste);
    m = min(a, m);
    t[i-1] = taste;
  }

  int sum = 0;
  bool isNegative = (l+n-1) < 0;
  if (isNegative) m = -m;
  for (int i=0; i<n; i++) {
    if (t[i] == m) continue;
    sum += t[i];
  }

  cout << sum << endl;
}
