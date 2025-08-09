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

int main() {
  string S, T;
  cin >> S >> T;
  int N = S.size();

  // アプローチ
  // S,Tに出現するアルファベットの個数をカウントしておく（mapとかで）
  // カウントが一致しないアルファベットが出現したら@で代用する
  // 代用する際に@のカウントを減らす
  // {atcoder}の文字以外だったら代用不可

  unordered_map<char, int> s_um;
  unordered_map<char, int> t_um;

  vector<char> C;
  for (char c = 'a'; c <= 'z'; ++c) {
    C.push_back(c);
    s_um[c] = 0;
    t_um[c] = 0;
  }
  C.push_back('@');

  rep(i, N) {
    s_um[S[i]]++;
    t_um[T[i]]++;
  }

  bool ok = true;
  string at = "atcoder";
  rep(i, C.size()) {
    if (C[i] == '@') continue;
    if (s_um[C[i]] > t_um[C[i]]) {
      int d = s_um[C[i]] - t_um[C[i]];
      if (d <= t_um['@']) {
        if (at.find(C[i]) != string::npos) t_um['@'] -= d;
        else ok = false;
      } else {
        ok = false;
      }
    } else if (s_um[C[i]] < t_um[C[i]]) {
      int d = t_um[C[i]] - s_um[C[i]];
      if (d <= s_um['@']) {
        if (at.find(C[i]) != string::npos) s_um['@'] -= d;
        else ok = false;
      } else {
        ok = false;
      }
    }
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}

