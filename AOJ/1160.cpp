
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

#define INF 1010000000
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vector<int> >;

int H,W;
vvi C;

int dx[8] = {1,1,0,-1,-1,-1, 0, 1};
int dy[8] = {0,1,1, 1, 0,-1,-1,-1};

void dfs(int h, int w) {
  C[h][w] = 0;

  // 8方向の探索
  for (int i=0; i<8; i++) {
    int nh = h + dx[i];
    int nw = w + dy[i];
    if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue; // 探索範囲外
    if (C[nh][nw] == 0) continue; // 海は探索スキップ
    dfs(nh, nw);
  }
}

int main() {
  cin >> H >> W;
  if (H == 0 || W == 0) cout << 0 << endl;
  C.assign(H, vi(W, false));
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> C[i][j];
    }
  }

  int result = 0;
  for (int h=0; h<H; h++) {
    for (int w=0; w<W; w++) {
      if (C[h][w] == 0) continue;
      dfs(h, w);
      result++;
    }
  }
  cout << result << endl;
}
