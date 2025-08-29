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
  map<char, int> alpha_map = {
    {'A', 0},
    {'B', 3},
    {'C', 4},
    {'D', 8},
    {'E', 9},
    {'F', 14},
    {'G', 23}
  };

  char p, q; cin >> p >> q;
  int r = 0;
  if (alpha_map[p] > alpha_map[q]) r = alpha_map[p] - alpha_map[q];
  else r = alpha_map[q] - alpha_map[p];

  cout << r << endl;
}

