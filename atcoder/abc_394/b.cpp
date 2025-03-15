#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> vs(n);
  for (int i = 0; i<n; i++) cin >> vs[i];
  vector<pair<int, string> > vp(n);
  for (int i = 0; i<n; i++) {
    int len = vs[i].size();
    vp.push_back(make_pair(len, vs[i]));
  }
  sort(vp.begin(), vp.end());
  for (auto p : vp) cout << p.second;
}
