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
using vvi = vector<vector<int>>;

int main() {
  int N;cin >> N;
  vs S(N);
  vi A(N), Ad(N);
  rep(i, N) cin >> S[i] >> A[i];

  Ad = A;
  sort(Ad.begin(), Ad.end());

  // 最年少の人のindexを保持
  int index = 0;
  rep(i, N) if (A[i] == Ad[0]) index=i;

  rep(i, N) {
    if (i < index) continue;
    cout << S[i] << endl;
  }
  rep(i, N) {
    if (i >= index) continue;
    cout << S[i] << endl;
  }
}

