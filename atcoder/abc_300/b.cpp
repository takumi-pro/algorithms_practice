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
  int h,w;
  cin >> h >> w;
  vector<vector<char> > a(h, vector<char>(w));
  vector<vector<char> > b(h, vector<char>(w));
  rep(i, h)rep(j, w) cin >> a[i][j];
  rep(i, h)rep(j, w) cin >> b[i][j];

  // 縦方向と横方向に分解する
  // 縦方向と横方向それぞれで#の数をカウントする
  // Bの各行の#の数の配列とAの各行の#の数の配列の並び順を比較
  // Bの各列の#の数の配列とAの各列の#の数の配列の並び順を比較

  // Bの各行の#の数を計算する
  // Bの各列の#の数を計算する
  vector<int> b_row_sharp_cnt;
  vector<int> b_column_sharp_cnt;
  rep(i, h) {
    int sharp_cnt = 0;
    rep(j, w) {
      if (b[i][j] == '#') sharp_cnt++;
    }
    b_row_sharp_cnt.push_back(sharp_cnt);
  }
  rep(i, w) {
    int sharp_cnt = 0;
    rep(j, h) {
      if (b[j][i] == '#') sharp_cnt++;
    }
    b_column_sharp_cnt.push_back(sharp_cnt);
  }

  // Aの各行の#の数を計算
  // Aの各列の#の数を計算
  vector<int> a_row_sharp_cnt;
  vector<int> a_column_sharp_cnt;
  rep(i, h) {
    int sharp_cnt = 0;
    rep(j, w) {
      if (a[i][j] == '#') sharp_cnt++;
    }
    a_row_sharp_cnt.push_back(sharp_cnt);
  }
  rep(i, w) {
    int sharp_cnt = 0;
    rep(j, h) {
      if (a[j][i] == '#') sharp_cnt++;
    }
    a_column_sharp_cnt.push_back(sharp_cnt);
  }

  bool row_match = false;
  int s = 0;
  rep(i, h) {
    bool match = true;
    rep(j, h) {
      if (a_row_sharp_cnt[j] != b_row_sharp_cnt[j]) match = false;
    }
    if (match) row_match = true;

    // 先頭要素を末尾に移動
    int top = b_row_sharp_cnt[0];
    b_row_sharp_cnt.erase(b_row_sharp_cnt.begin());
    b_row_sharp_cnt.push_back(top);
    s++;
  }

  bool column_match = false;
  int t = 0;
  rep(i, w) {
    bool match = true;
    rep(j, w) {
      if (a_column_sharp_cnt[j] != b_column_sharp_cnt[j]) match = false;
    }
    if (match) column_match = true;

    // 先頭要素を末尾に移動
    int top = b_column_sharp_cnt[0];
    b_column_sharp_cnt.erase(b_column_sharp_cnt.begin());
    b_column_sharp_cnt.push_back(top);
    t++;
  }

  if (row_match && column_match) cout << "Yes" << endl;
  else cout << "No" << endl;

  cout << "s: " << s << ", t: " << t << endl;
  // 横方向を動かすパターン
  // 縦方向で計算したシフトの分のループ内でw-1のループを回す
  //   Aの各列の#の数を計算してBと一致するシフトを記憶しておく
}

// 解答コード
// アプローチとしては全探索だが、効率を上げるため探索範囲を絞っている
// あとはmodを使ってる
// まずは縦方向と横方向に移動する分だけのループをしている（s, t）
// 次にAの各行各列全てにおいて縦方向にs回、横方向にt回移動した際にBと一致するかを判定している
// 一致しない位置が一つでもあればNoを出力
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H), B(H);
  for (auto& x : A) cin >> x;
  for (auto& x : B) cin >> x;
  for (int s = 0; s < H; s++) {
    for (int t = 0; t < W; t++) {
      int ok = 1;
      for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
          if (A[(i - s + H) % H][(j - t + W) % W] != B[i][j]) ok = 0;
        }
      }
      if (ok) {
        cout << "Yes" << endl;
        exit(0);
      }
    }
  }
  cout << "No" << endl;
}

