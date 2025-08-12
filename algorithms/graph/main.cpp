#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;
using vvi = vector<vector<int> >;

int main() {
  // 頂点数と辺数を受け取る
  int N, M; cin >> N >> M;

  // グラフ
  vvi G(N);

  // 辺数の分だけの入力がある
  // どの頂点を結ぶ辺かが与えられる
  for (int i=0; i<M; i++) {
    int a,b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a); // 無向グラフを想定
  }

  for (int i=0; i<N; i++) {
    string s = "{";
    for (int n : G[i]) s += to_string(n) + ",";
    cout << s.substr(0, s.size()-1) << "}" << endl;
  }
}
