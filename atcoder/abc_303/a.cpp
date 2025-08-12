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

int main() {
  int N;cin >> N;
  string S,T;
  cin >> S >> T;

  bool ok = true;
  rep(i, N) {
    if (
      !(S[i] == T[i] ||
      S[i] == '1' && T[i] == 'l' ||
      S[i] == 'l' && T[i] == '1' ||
      S[i] == '0' && T[i] == 'o' ||
      S[i] == 'o' && T[i] == '0')
    )
      ok = false;
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}

