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
  int N,M;cin >> N >> M;
  vs S(N);
  rep(i, N) cin >> S[i];

  // sortがないとWAになるケースがあった
  // sortしないとnext_permutationsは正常に動かない？
  sort(S.begin(), S.end());

  // 順列を全列挙して条件を満たすものを探す
  do {
    bool ok = true;
    for (int i=0; i<N-1; i++) {
      int d = 0;
      for (int j=0; j<M; j++) {
        if (S[i][j] != S[i+1][j]) d++;
      }
      if (d != 1) ok = false;
    }
    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  } while (next_permutation(S.begin(), S.end()));

  cout << "No" << endl;
}

