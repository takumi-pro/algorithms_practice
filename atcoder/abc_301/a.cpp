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
  int n;
  string s;
  cin >> n >> s;
  int a_cnt = 0;
  rep(i, n) {
    if (s[i] == 'A') a_cnt++;
  }
  if (a_cnt > (n - a_cnt)) cout << "A" << endl;
  else if (a_cnt == (n - a_cnt)) {
    if (s.back() == 'A') {
      cout << "T" << endl;
    } else {
      cout << "A" << endl;
    }
    return 0;
  } else {
    cout << "T" << endl;
  }
}

