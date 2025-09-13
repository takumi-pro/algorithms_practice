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
using vvb = vector<vector<bool> >;

int main() {
  int N,M,H,K;cin >> N >> M >> H >> K;
  string S;cin >> S;
  vector<ll> x(M),y(M);
  for (int i=0; i<M; i++) cin >> x[i] >> y[i];

  // アイテムの位置をsetを用いて管理する
  set<pair<int, int> > item_set;
  for (int i=0; i<M; i++) item_set.insert({x[i], y[i]});

  int res = true;
  int n = S.size();
  pair<int, int> curr = {0, 0};
  for (int i=0; i<n; i++) {
    if (S[i] == 'R') curr.first++;
    if (S[i] == 'L') curr.first--;
    if (S[i] == 'U') curr.second++;
    if (S[i] == 'D') curr.second--;
    H--;
    if (H < 0) {
      res = false;
      break;
    }
    if (H < K && item_set.find(curr) != item_set.end()) {
      H = K;
      item_set.erase(curr);
    }
  }

  if (res) cout << "Yes" << endl;
  else cout << "No" << endl;
}

