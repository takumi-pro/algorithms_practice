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
using vvi = vector<vector<int>>;

// unordered_mapのkeyにpairを使えるようにするため
template<class T> size_t HashCombine(const size_t seed,const T &v){
  return seed^(std::hash<T>()(v)+0x9e3779b9+(seed<<6)+(seed>>2));
}
/* pair用 */
template<class T,class S> struct std::hash<std::pair<T,S>>{
  size_t operator()(const std::pair<T,S> &keyval) const noexcept {
      return HashCombine(std::hash<T>()(keyval.first), keyval.second);
  }
};

int dx[8] = {1,1,0,-1,-1,-1, 0, 1};
int dy[8] = {0,1,1, 1, 0,-1,-1,-1};
int dx_4[4] = {1, 0, -1,  0};
int dy_4[4] = {0, 1,  0, -1};

int main() {
  int H, W;cin >> H >> W;
  vector<string> S(H);
  for (int i=0; i<H; i++) cin >> S[i];

  int x=-1,y=-1;
  for (int h=0; h<H; h++) {
    for (int w=0; w<W; w++) {
      if (S[h][w] == '#') continue;
      bool x_flg = false, y_flg = false;
      for (int i=0; i<4; i++) {
        int nh = h + dx_4[i];
        int nw = w + dy_4[i];
        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if (dx_4[i] != 0 && S[nh][nw] == '#') x_flg = true;
        if (dy_4[i] != 0 && S[nh][nw] == '#') y_flg = true;
      }
      if (x_flg && y_flg) x=h,y=w;
    }
  }

  cout << x+1 << " " << y+1 << endl;
}

