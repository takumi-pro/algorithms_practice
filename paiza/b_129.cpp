#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

int main() {
  int n,m,h,w;
  cin >> n >> m >> h >> w;
  map<int, int> amount;
  vector<vector<char> > v(h+1, vector<char>(w+1, '.'));
  vector<int> e_arr(n);
  vector<vector<int> > abcd_arr(n, vector<int>(4));

  for (int i=0; i<n; i++) {
    cin >> abcd_arr[i][0] >> abcd_arr[i][1] >> abcd_arr[i][2] >> abcd_arr[i][3] >> e_arr[i];
  }

  for (int n_i=0; n_i<n; n_i++) {
    for (int i=1; i<=h; i++) {
      for (int j=1; j<=w; j++) {
        if (i >= abcd_arr[n_i][0] && i <= abcd_arr[n_i][1] && j >= abcd_arr[n_i][2] && j <= abcd_arr[n_i][3]) {
          if (v[i][j] != '.') amount[v[i][j] - '0']++;
          v[i][j] = e_arr[n_i] + '0';
        }
      }
    }
  }

  for (int i=0; i<m; i++) {
    if (amount.find(i+1) != amount.end()) cout << amount[i+1] << endl;
    else cout << 0 << endl;
  }

  for (int i=1; i<=h; i++) {
    for (int j=1; j<=w; j++) {
      cout << v[i][j];
    }
    cout << endl;
  }
}
