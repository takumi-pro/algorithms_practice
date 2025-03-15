#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

#define INF 1010000000

using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(m);
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<m; i++) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int i = 0;
  int j = 0;
  int ans = INF;
  while ((i < n) && (j < m)) {
    ans = min(ans, abs(a[i] - b[j]));
    if (a[i] < b[j]) i++;
    else j++;
  }
  cout << ans << endl;
}
