#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

#define INF 1010000000

using namespace std;
using ll = long long;

int main() {
  string s; cin >> s;
  int curr = 1;
  int res = 0;
  for (auto c : s) {
    if (curr%2==0 && c == 'i' || curr%2!=0 && c == 'o') {
      res++;
      curr++;
    }
    curr++;
  }
  if (s[s.size()-1] == 'i') res++;
  cout << res << endl;
}
