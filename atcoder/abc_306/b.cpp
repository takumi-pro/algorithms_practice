#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <cmath>

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
  vector<int> A(64);
  for (int i=0; i<64; i++) cin >> A[i];
  unsigned long long sum = 0; 
  for (int i=0; i<64; i++) {
    if (A[i] == 0) continue;
    unsigned long long pow = 1;
    for (int j=0; j<i; j++) pow *= 2;
    sum += pow;
  }

  cout << sum << endl;
}

