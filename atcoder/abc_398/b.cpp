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
  unordered_map<int, int> m;
  rep(i, 7) {
    int a; cin >> a;
    m[a]++;
  }

  bool flg_3 = false;
  bool flg_2 = false;
  // 反省：最も頻度の高いものが3以上で次に頻度が高いものが2以上であればOK！
  for (auto it : m) {
    if(it.second == 3) flg_3 = true;
    if(it.second == 2) flg_2 = true;
  }
  for (auto it : m) {
    if(it.second == 4) flg_3 = true;
    if(it.second == 2) flg_2 = true;
  }
  for (auto it : m) {
    if(it.second == 5) flg_3 = true;
    if(it.second == 2) flg_2 = true;
  }
  for (auto it : m) {
    if(it.second == 3) flg_3 = true;
    if(it.second == 4) flg_2 = true;
  }
  int c = 0;
  for (auto it : m) {
    if(it.second == 3) c++;
    // if(it.second == 3) flg_2 = true;
  }

  cout << ((flg_2 && flg_3 || c == 2) ? "Yes" : "No") << endl;
}
