#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>

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

int main() {
  string S;cin >> S;
  long double ans = 0;
  if (S.size() < 3) {
    cout << 0 << endl;
    return 0;
  }
  for (int i=0; i<S.size()-2; i++) {
    if (S[i] != 't') continue;

    for (int j=i+2; j<S.size(); j++) {
      if (S[j] != 't') continue;

      int x = 0;
      for (int k=i; k<=j; k++) if (S[k] == 't') x++;
      int t_n = j - i + 1;
      long double r = (long double)(x-2)/(long double)(t_n-2);
      ans = max(ans, r);
    }
  }

  cout << fixed << setprecision(15) << ans << endl;
}

