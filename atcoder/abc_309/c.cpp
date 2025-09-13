#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>

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
  ll N, K; cin >> N >> K;
  vector<ll> m(1000000001, 0);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, std::greater<pair<ll, ll> > > q;

  ll sum = 0;
  rep(i, N) {
    ll a,b; cin >> a >> b;
    q.push(make_pair(a, b));
    sum += b;
  }

  ll ans = 1;
  if (sum <= K) {
    cout << "1日目!" << endl;
    cout << "sum: " << sum << ", K: " << K << endl;
    cout << ans << endl;
    return 0;
  }

  for (int i=2; i<N; i++) { // 2日~N日
    if (i > q.top().first) {
      sum -= q.top().second;
      q.pop();
    }

    if (sum <= K) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;
}

