#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

#define INF 1010000000
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

// 隣接リスト形式でグラフ問題を解く
int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);
  rep(i, m) cin >> a[i] >> b[i];

  // G[v]のリストを用意する
  vector<vector<int> > G(n+1);

  // 無向グラフなので1→2と2→1の2つを挿入する必要がある
  rep(i, m) {
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }

  for (int i=1; i<=n; i++) {
    cout << "G[" << i << "]" << ": ";
    rep(j, G[i].size()) {
      cout << G[i][j] << ",";
    }
    cout << endl;
  }

  for (int i=1; i<=n; i++) {
    string res;
    rep(j, G[i].size()) {
      res += to_string(G[i][j]) + ", ";
    }
    res.erase(res.size()-2, 2);
    cout << i << ": {" << res << "}" << endl;
  }
}
