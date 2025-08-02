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
  int n;cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<pair<int, int> > scores;
  rep(i, n) scores.push_back(make_pair(a[i], i+1));
  sort(scores.rbegin(), scores.rend());
  cout << scores[1].second << endl;
}
