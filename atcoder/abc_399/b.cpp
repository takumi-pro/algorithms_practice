#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

#define INF 1010000000
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];

  unordered_map<int, int> mf;
  unordered_map<int, int> mr;
  int r = 1;
  rep(i, n) {
    mf[p[i]]++;
    mr[p[i]] = r;
  }

  vector<int> u;
  for (auto it : mf) {
    u.push_back(it.first);
  }
  int s = u.size();

  rep(i, s) {
    sort(u.rbegin(), u.rend());
    mr[u[0]] = r;
    r += mf[u[0]];
    u.erase(u.begin());
  }

  rep(i, n) {
    cout << mr[p[i]] << endl;
  }
}

