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

int H, W;
vector<string> C;
int dx[4] = {1,0,-1, 0};
int dy[4] = {0,1, 0,-1};

void dfs(int sx, int sy, vector<vector<bool> > &seen) {
  seen[sx][sy] = true;

  // 4方向に対して探索を進める
  for (int i=0; i<4; i++) {
    int nh = sx + dx[i];
    int nw = sy + dy[i];
    if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
    if (C[nh][nw] == '#') continue;
    if (seen[nh][nw]) continue;
    dfs(nh, nw, seen);
  }
}

int main() {
  cin >> H >> W;
  C.resize(H);
  for (int i=0; i<H; i++) cin >> C[i];

  // sとtの場所を特定する
  int sx, sy, tx, ty;
  for (int h=0; h<H; h++) {
    for (int w=0; w<W; w++) {
      if (C[h][w] == 's') {
        sx = h;
        sy = w;
      }
      if (C[h][w] == 'g') {
        tx = h;
        ty = w;
      }
    }
  }

  // seen配列
  vector<vector<bool> > seen(H+1, vector<bool>(W+1, false));
  dfs(sx, sy, seen);

  // tx, tyの位置のseenがtrueだったら到達できている
  if (seen[tx][ty]) cout << "Yes" << endl;
  else cout << "No" << endl;
}

