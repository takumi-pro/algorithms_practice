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

template<class T> size_t HashCombine(const size_t seed,const T &v){
  return seed^(std::hash<T>()(v)+0x9e3779b9+(seed<<6)+(seed>>2));
}
/* pair用 */
template<class T,class S> struct std::hash<std::pair<T,S>>{
  size_t operator()(const std::pair<T,S> &keyval) const noexcept {
      return HashCombine(std::hash<T>()(keyval.first), keyval.second);
  }
};

int main() {
  int N,M;cin >> N >> M;
  vvi a(M, vi(N));
  rep(i, M)rep(j, N) cin >> a[i][j];
 
  // N人いるので2組選ぶ組み合わせを列挙する
  // 組み合わせをpair型のmapに保持しておく
  unordered_map<pair<int, int>, int> pum;
  vi nums(N);
  rep(i, N) nums[i] = i+1;
  int it = 0;
  while (it < N) {
    for (int i=it+1; i < N; i++) {
      pum[make_pair(nums[it], nums[i])] = 0;
    }
    it++;
  }

  // M回分の組み合わせの出現カウントをして0だった組み合わせ数を答えとして出力
  rep(i, M) {
    for (int j=0; j<N-1; j++) {
      // 小さい順に並べる
      int l = a[i][j], r = a[i][j+1];
      if (l > r) {
        int tmp = l;
        l = r;
        r = tmp;
      }
      pum[make_pair(l, r)]++;
    }
  }
  int ans = 0;
  for (auto pair : pum) {
    if (pair.second == 0) ans++;
  }

  cout << ans << endl;
}

