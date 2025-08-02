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
  int h,w,n; cin >> h >> w >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n) cin >> a[i] >> b[i];
  
  vector<int> cp_a = a;
  sort(cp_a.begin(), cp_a.end());
  cp_a.erase(unique(cp_a.begin(), cp_a.end()), cp_a.end());
  
  vector<int> cp_b = b;
  sort(cp_b.begin(), cp_b.end());
  cp_b.erase(unique(cp_b.begin(), cp_b.end()), cp_b.end());

  rep(i, n) {
    int ans_a = lower_bound(cp_a.begin(), cp_a.end(), a[i]) - cp_a.begin() + 1;
    int ans_b = lower_bound(cp_b.begin(), cp_b.end(), b[i]) - cp_b.begin() + 1;
    cout << ans_a << " " << ans_b << endl;
  }
}
