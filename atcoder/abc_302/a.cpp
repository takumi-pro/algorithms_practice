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

int main() {
  ll a,b; cin >> a >> b;
  ll ans = a/b;
  if (a%b!=0) ans++;
  cout << ans << endl;
}

