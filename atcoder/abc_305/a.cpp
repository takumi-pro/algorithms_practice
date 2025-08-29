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
  // 55で割ったあまりを求める
  // 0だったらそのまま出力
  // 1,2だったらあまりを引いた数を出力
  // 3,4だったら
  int r = N % 5;
  if (r == 0) cout << N << endl;
  else if (r == 1 || r == 2) cout << N-r << endl;
  else cout << N+(5-r) << endl;
}

