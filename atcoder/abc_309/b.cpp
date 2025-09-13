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
  vs A(N);
  vvi B(N, vi(N)), a(N, vi(N));
  rep(i, N) cin >> A[i];
  rep(i, N) {
    rep(j, N) {
      if (A[i][j] == '0') a[i][j] = 0;
      else a[i][j] = 1;
    }
  }

  rep(i, N) {
    rep(j, N) {
      if (i == 0) {
        if (j == 0) B[i][j] = a[i+1][0];
        else B[i][j] = a[i][j-1];
      } else if (i == N-1) {
        if (j == N-1) B[i][j] = a[i-1][N-1];
        else B[i][j] = a[i][j+1];
      } else if (j == 0) {
        if (i == N-1) B[i][j] = a[i][j+1];
        else B[i][j] = a[i+1][j];
      } else if (j == N-1) {
        if (i == 0) B[i][j] = a[i][j-1];
        else B[i][j] = a[i-1][j];
      } else {
        B[i][j] = a[i][j];
      }
    }
  }

  rep(i, N) {
    rep(j, N) {
      cout << B[i][j];
    }
    cout << endl;
  }
}

