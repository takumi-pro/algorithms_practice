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

const int dx[8] = {1,1,0,-1,-1,-1, 0, 1};
const int dy[8] = {0,1,1, 1, 0,-1,-1,-1};

// const int dy[4] = {-1,0,1,0};
// const int dx[4] = {0,1,0,-1};

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

int main() {
  int N;cin >> N;
  vector<ll> x(N),y(N);
  vector<vector<ll> > dp(N+1, vector<ll>(2, -1000000000));
  for (int i=0; i<N; i++) cin >> x[i] >> y[i];
  dp[0][0] = 0;

  for (int i=0; i<N; i++) {
    if (x[i] == 0) { // i番目の料理が解毒剤入りの場合
      dp[i+1][0] = max(dp[i][0], max(dp[i][0], dp[i][1]) + y[i]);
      dp[i+1][1] = max(dp[i+1][1], dp[i][1]);
    } else { // i番目の料理が毒入りの場合
      dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
      dp[i+1][1] = max(dp[i][0] + y[i], dp[i][1]);
    }
  }

  cout << max(dp[N][0], dp[N][1]) << endl;
}

