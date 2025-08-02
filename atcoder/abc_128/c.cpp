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
  int n,m; cin >> n >> m;
  vector<vector<int> > s(m);
  vector<int> p(m);
  rep(i, m) {
    int k; cin >> k;
    rep(j, k) {
      int si; cin >> si;
      s[i].push_back(si-1);
    }
  }
  rep(i, m) cin >> p[i];

  int ans = 0;
  for (int i = 0; i<(1<<n); i++) {
    int ok = 0;
    rep(k, m) {
      int sum = 0;
      rep(l, s[k].size()) {
        if (i & (1 << s[k][l]))  sum++;
      }
      if (sum%2 == p[k]) ok++;
    }
    if (ok == m) ans++;
  }

  cout << ans << endl;
}
