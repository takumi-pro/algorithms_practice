#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;
using vvi = vector<vector<int> >;

void dfs(const vvi &G, int v, vector<bool> &seen) {
  seen[v] = true;

  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;
    dfs(G, next_v, seen);
  }
}

int main() {
  // 頂点数と辺数を受け取る
  int N, M; cin >> N >> M;

  // グラフ
  vvi G(N);

  // seen配列
  vector<bool> seen(M, false);

  // 辺数の分だけの入力がある
  // どの頂点を結ぶ辺かが与えられる
  for (int i=0; i<M; i++) {
    int a,b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a); // 無向グラフを想定
  }

  dfs(G, 0, seen);

//  for (int i=0; i<N; i++) {
//    string s = "{";
//    for (int n : G[i]) s += to_string(n) + ",";
//    cout << s.substr(0, s.size()-1) << "}" << endl;
//  }

  // 頂点が探索されたかを出力する
  for (int i=0; i<N; i++) {
    cout << "頂点: " << i << ", ";
    if (seen[i]) cout << "探索済み";
    else cout << "探索してないよ";
    cout << endl;
  }
}
