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

int main() {
  int q; cin >> q;
  std::priority_queue<
    ll,
    std::vector<ll>,
    std::greater<ll>
  > que;
  ll plus = 0;
  vector<vector<ll> > query(q, vector<ll>(2));
  rep(i, q) {
    ll p, x;
    cin >> p;
    if (p != 3) cin >> x;
    query[i][0] = p;
    query[i][1] = x;
  }

  rep(i, q) {
    ll p = query[i][0];
    ll x = query[i][1];
    if (p == 1) que.push(x - plus);
    if (p == 2) plus += x;
    if (p == 3) {
      ll top = que.top();
      cout << top + plus << endl;
      que.pop();
    }
  }
}
