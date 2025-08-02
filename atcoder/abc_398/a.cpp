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
  string s(n, '-');
  if (n == 1) {
    cout << "=" << endl;
    return 0;
  }

  bool flg = false;
  if (n%2==0) flg = true;
  int half = n/2;
  rep(i, n) {
    if (i == half) {
      s[i] = '=';
      if (flg) s[i-1] = '=';
    }
  }
  cout << s << endl;
}
