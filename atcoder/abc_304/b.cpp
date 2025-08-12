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
  int N; cin >> N;

  if (N <= (1e3 - 1)) cout << N << endl;
  if (N >= 1e3 && N <= 1e4 - 1) cout << (N/10) * 10 << endl;
  if (N >= 1e4 && N <= 1e5 - 1) cout << (N/100) * 100 << endl;
  if (N >= 1e5 && N <= 1e6 - 1) cout << (N/1000) * 1000 << endl;
  if (N >= 1e6 && N <= 1e7 - 1) cout << (N/10000) * 10000 << endl;
  if (N >= 1e7 && N <= 1e8 - 1) cout << (N/100000) * 100000 << endl;
  if (N >= 1e8 && N <= 1e9 - 1) cout << (N/1000000) * 1000000 << endl;
}

