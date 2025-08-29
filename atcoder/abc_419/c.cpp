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
  ll N;cin >> N;
  vector<ll> R(N), C(N);
  for (int i=0; i<N; i++) cin >> R[i] >> C[i];
  
  // 平均を求める
  ll x_sum = 0, y_sum = 0;
  for (int i=0; i<N; i++) {
    x_sum += R[i];
    y_sum += C[i];
  }
  ll x_avg = x_sum / N;
  ll y_avg = y_sum / N;

  // 目指すべき最短値は{x_avg, y_avg}
  
  // 各人が最短値に到達するのにかかる時間
  vector<ll> l(N);
  vector<ll> dx_l(N);
  vector<ll> dy_l(N);
  for (int i=0; i<N; i++) {
    ll dx = abs(R[i] - x_avg);
    ll dy = abs(C[i] - y_avg);
    dx_l.push_back(dx);
    dy_l.push_back(dy);
  }

  sort(dx_l.rbegin(), dx_l.rend());
  long long ans_x = (dx_l[0] + dx_l[1]) / 2;

  sort(dy_l.rbegin(), dy_l.rend());
  long long ans_y = (dy_l[0] + dy_l[1]) / 2;

  long long ans = max(ans_x, ans_y);

  // sort(l.rbegin(), l.rend());
  // long long ans = (l[0] + l[1]) / 2;

  cout << ans << endl;
}

