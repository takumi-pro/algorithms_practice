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

int main() {
  int N; cin >> N;
  vi a(N);
  rep(i, N) cin >> a[i];
  unordered_map<int, vector<int> > insert_nums; // 挿入数列

  for (int i=0; i<N-1; i++) {
    if (abs(a[i] - a[i+1]) == 1) continue;

    if (a[i] < a[i+1]) {
      for (int ai = a[i]+1; ai < a[i+1]; ai++) {
        insert_nums[i].push_back(ai);
      }
    } else if (a[i] > a[i+1]) {
      for (int ai = a[i]-1; ai > a[i+1]; ai--) {
        insert_nums[i].push_back(ai);
      }
    }
  }

  rep(i, N) {
    cout << a[i] << " ";

    // 挿入する数列がある場合
    if (insert_nums.find(i) != insert_nums.end()) {
      rep(j, insert_nums[i].size()) cout << insert_nums[i][j] << " ";
    }
  }
}

