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
  int n;cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int left = 0,left_cnt = 0;
  int right = n-1,right_cnt = 0;
  vector<int> l;
  vector<int> r;
  set<int> ls;
  set<int> rs;
  while (left < n) {
    decltype(ls)::iterator lit = ls.find(a[left]);
    decltype(rs)::iterator rit = rs.find(a[right]);

    if (lit == ls.end()) left_cnt++;
    if (rit == rs.end()) right_cnt++;

    // mapping
    l.push_back(left_cnt);
    r.push_back(right_cnt);

    ls.insert(a[left]);
    rs.insert(a[right]);

    // index更新
    left++;
    right--;
  }

  
  reverse(r.begin(), r.end());
  int m = -1;
  rep(i, n-1) m = max(m, (l[i] + r[i+1]));
  cout << m << endl;
}
