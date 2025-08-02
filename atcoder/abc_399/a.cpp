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
  int n;
  string s, t;
  cin >> n >> s >> t;
  int cnt = 0;
  rep(i, n) {
    if (s[i] != t[i]) cnt++;
  }
  cout << cnt << endl;
}
