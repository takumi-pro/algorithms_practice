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
  // 体力Hが移動数N以上だった場合はアイデムを使わずに移動できるためYesを出力する
  // 体力HがK未満になるタイミングと体力Hが0になるタイミングが鍵
  // 体力HがK未満の状態で、その場所にアイテムがある場合はHを回復して再度移動
  // 体力Hが0になるタイミングで、移動先にアイテムがなければNoを出力

  // HがN以上→Yes出力
  // HがK未満になるまで移動 → RLUDについてはまとめて+-できる
  // K未満の場合
  // -- その場所にアイテムがある→回復
  // -- その場所にアイテムがない
  // ----継続
  // 0になった場合
  // -- 次の場所にアイテムがない→No出力

  int N,M,H,K; cin >> N >> M >> H >> K;
  string S; cin >> S;
  vvi xy;
  rep(i, M) cin >> xy[i][0] >> xy[i][1];

  if (H > N) {
    cout << "Yes" << endl;
    return 0;
  }

  // Hが正の整数 or Nが正の整数の間ループ
  int s_i = 0;
  while (H > 0 || N > 0) {
    // Hが50, Kが20の場合はHが19だから
    int d = H - (H-K) - 1; // K未満の値
    int x, y;
    for (int i = s_i; i < d; i++) {
      if (S[i] == 'R') x++;
      if (S[i] == 'L') x--;
      if (S[i] == 'U') y++;
      if (S[i] == 'D') y--;
    }
    H = H - d;
    N = N - d;
    // x, yの場所は体力がK未満になった場所なのでここでアイテムがあるかを確認する
    bool item_f = false;
    rep(m, M) {
      if (xy[m][0] == x && xy[m][1] == y) item_f = true;
    }
    if (item_f) {
      H = K;
    }

    if (H == 0) {

    }

    // KがH以上の場合を考慮する todo
  }
}

