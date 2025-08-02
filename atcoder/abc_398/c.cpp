#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

#define INF 1010000000
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  unordered_map<int, int> mf;
  unordered_map<int, int> mn;
  // vector<pair<int, int> > pa;
  rep(i, n) {
    mf[a[i]]++; // 数と頻度
    mn[a[i]] = i+1; // 数と人番号
  }

  vector<pair<int, int> > p;
  for (auto it : mf) {
    if (it.second == 1) {
      p.push_back(make_pair(it.first, mn[it.first]));
    }
  }

  sort(p.rbegin(), p.rend());
  cout << ((p.size() == 0) ? -1 : p[0].second) << endl;
}
