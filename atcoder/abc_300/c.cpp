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

int main() {
  // アプローチ
  // サイズが小さいバツ印から探索していく
  // まずはサイズ1から（C[0][0]~C[H-1][W-1]とする）
  //   サイズ1はC[1][1]からC[H-2][W-2]までを探索する
  //   グリッドが#のマスで条件に当てはまるものを探索すれば良さそう
  // それをサイズS_Nまで繰り返す
  // 計算量はmin(H, W)ループの中にHWがあるので → 最悪100^3 → 10^6

  int H,W;
  cin >> H >> W;
  vector<vector<char> > C(H, vector<char>(W));
  vector<vector<char> > Cd(H+2, vector<char>(W+2, '.'));
  rep(i, H)rep(j, W) cin >> C[i][j];
  for(int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      Cd[h+1][w+1] = C[h][w];
    }
  }

  int N = min(H, W);
  vector<int> ans(N);
  for (int n = 1; n <= N/2; n++) {

    int cnt = 0;

    for (int h = n; h < H-n; h++) {
      for (int w = n; w < W-n; w++) {
        // 中心グリッドが#じゃない場合は次のループ
        if (C[h][w] != '#') continue;

        // 1≤d≤n を満たす整数 d について、 C[a+d][b+d],C[a+d][b−d],C[a−d][b+d],C[a−d][b−d] はいずれも # であるかどうか
        bool condition = true;
        for (int d = 1; d <= n; d++) {
          if (
            !(C[h+d][w+d] == '#' &&
            C[h+d][w-d] == '#' &&
            C[h-d][w+d] == '#' &&
            C[h-d][w-d] == '#')
          ) {
            condition = false;
          }
        }
        if (!condition) continue;

        // C[a+n+1][b+n+1],C[a+n+1][b−n−1],C[a−n−1][b+n+1],C[a−n−1][b−n−1] のうち少なくとも 1 つは . であるかどうか
        condition = true;
        if (
          Cd[h+n+2][w+n+2] == '#' &&
          Cd[h+n+2][w-n] == '#' &&
          Cd[h-n][w+n+2] == '#' &&
          Cd[h-n][w-n] == '#'
        ) {
          condition = false;
        }
        if (!condition) continue;
        cnt++;
      }
    }

    ans[n-1] = cnt;
  }

  rep(i, N) cout << ans[i] << " ";
}

