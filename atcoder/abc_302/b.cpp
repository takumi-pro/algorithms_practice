#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

#define INF 1010000000
#define rep(i, n) for(int i=0; i<n; i++)

const int di[] = {-1,0,1};
const int dj[] = {-1,0,1};

using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
  int H,W; cin >> H >> W;
  vector<string> S(H);
  rep(i, H) cin >> S[i];
  vector<vector<int>> ans(5, vector<int>(2));

  rep(h, H) {
    rep(w, W) {
      if (S[h][w] != 's') continue;

      // 周辺のマスを調べる
      for (int i : di) {
        for (int j : dj) {
          if (i == 0 && j == 0) continue; // そのマス自体はスキップ
          if (
            h+i < H && h+i >= 0 && w+j >= 0 && w+j < W && S[h+i][w+j] == 'n' &&
            h+i+i < H && h+i+i >= 0 && w+j+j >= 0 && w+j+j < W && S[h+i+i][w+j+j] == 'u' &&
            h+i+i+i < H && h+i+i+i >= 0 && w+j+j+j >= 0 && w+j+j+j < W && S[h+i+i+i][w+j+j+j] == 'k' &&
            h+i+i+i+i < H && h+i+i+i+i >= 0 && w+j+j+j+j >= 0 && w+j+j+j+j < W && S[h+i+i+i+i][w+j+j+j+j] == 'e'
          ) {
            ans = {
              {h, w},
              {h+i, w+j},
              {h+i+i, w+j+j},
              {h+i+i+i, w+j+j+j},
              {h+i+i+i+i, w+j+j+j+j},
            };
          }
        }
      }
    }
  }

  rep(i, 5) {
    rep(j, 2) {
      cout << ans[i][j]+1 << " ";
    }
    cout << endl;
  }
}

