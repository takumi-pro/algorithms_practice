#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0; i<n; i++) cin >> a[i];

  bool flg = true;
  for (int i=0; i<n-1; i++) {
    if (a[i] >= a[i+1]) flg = false;
  }

  cout << (flg ? "Yes" : "No") << endl;
}
