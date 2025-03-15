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

  unordered_map<int, vector<int> > m;

  for (int i=0; i<n; i++) {
    m[a[i]].push_back(i);
  }

  int ans = 1000001;
  for (auto it : m) {
    vector<int> indexes = it.second;
    sort(indexes.begin(), indexes.end());
    if (indexes.size() == 1) continue;
    for (int i=0; i<indexes.size()-1; i++) {
      ans = min(ans, indexes[i+1] - indexes[i] + 1);
    }
  }

  cout << (ans == 1000001 ? -1 : ans) << endl;
}
