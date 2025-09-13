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

// const int dx[8] = {1,1,0,-1,-1,-1, 0, 1};
// const int dy[8] = {0,1,1, 1, 0,-1,-1,-1};

const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

// unordered_mapのkeyにpairを使えるようにするため
template<class T> size_t HashCombine(const size_t seed,const T &v){
  return seed^(std::hash<T>()(v)+0x9e3779b9+(seed<<6)+(seed>>2));
}
/* pair用 */
template<class T,class S> struct std::hash<std::pair<T,S> >{
  size_t operator()(const std::pair<T,S> &keyval) const noexcept {
      return HashCombine(std::hash<T>()(keyval.first), keyval.second);
  }
};

int H,W;
vs S;
vector<vector<bool> > C;

unordered_map<char, char> um = {
  {'s', 'n'},
  {'n', 'u'},
  {'u', 'k'},
  {'k', 'e'},
  {'e', 's'},
};

void dfs(int h, int w) {
  C[h][w] = true;

  for (int i=0; i<4; i++) {
    int nh = h + dx[i];
    int nw = w + dy[i];
    if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue; // 範囲外
    if (C[nh][nw]) continue;
    if (um.find(S[nh][nw]) != um.end() && S[nh][nw] == um[S[h][w]]) {
      dfs(nh, nw); 
    }
  }
};

int main() {
  cin >> H >> W;
  S.assign(H, "");
  C.assign(H, vector<bool>(W, false));
  for (int i=0; i<H; i++) cin >> S[i];
  dfs(0, 0);
  if (C[H-1][W-1]) cout << "Yes" << endl;
  else cout << "No" << endl;
}

