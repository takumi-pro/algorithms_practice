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

int main() {
  int n; cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];

  vector<int> a = p;
  sort(a.rbegin(), a.rend());

  a.erase(unique(a.begin(), a.end()), a.end());

  vector<int> d;
  rep(i, p.size()) {
    int ans = lower_bound(a.begin(), a.end(), p[i]) - a.begin();
    d.push_back(ans);
  }
  rep(i, d.size()) {
    cout << d[i] << ",";
  }
}

