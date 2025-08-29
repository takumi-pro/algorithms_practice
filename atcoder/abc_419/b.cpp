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

int main() {
  int Q;cin >> Q;
  vector<int> f;

  for (int i=0; i<Q; i++) {
    int q;cin >> q;
    if (q == 1) {
      int x; cin >> x;
      f.push_back(x);
    } else if (q == 2) {
      sort(f.begin(), f.end());
      cout << f[0] << endl;
      f.erase(f.begin());
    }
  }
}


