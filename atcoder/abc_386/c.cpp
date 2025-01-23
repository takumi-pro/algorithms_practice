#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

int main() {
  int k;
  string s,t;
  cin >> k >> s >> t;

  string result = "Yes";
  int t_n = t.size(), s_n = s.size(), th_n = t.size()/2, sh_n = s.size()/2;
  if (s.size() == t.size()) {
    int diff = 0;
    for (int i=0; i<s_n; i++) {
      if (s[i] != t[i]) diff++;
    }
    if (diff > 1) result = "No";
  }

  if (s.size() == t.size() + 1) {
    if (t.size() == 1) {
      if (t[0] != s[0] && t[0] != s[1]) result = "No";
    }

    for (int i=0; i<=th_n; i++) {
      int left = i, t_right = t.size()-1-i, s_right = s.size()-1-i;
      if (s[left] != t[left]) {
        if (s.erase(left, 1) != t) result = "No";
        break;
      }
      if (s[s_right] != t[t_right]) {
        if (s.erase(s_right, 1) != t) result = "No";
        break;
      }
    }
  }

  if (s.size() + 1 == t.size()) {
    if (s.size() == 1) {
      if (s[0] != t[0] && s[0] != t[1]) result = "No";
    }

    for (int i=0; i<=sh_n; i++) {
      int left = i, s_right = s.size()-1-i, t_right = t.size()-1-i;
      if (t[left] != s[left]) {
        if (t.erase(left, 1) != s) result = "No";
        break;
      }
      if (t[t_right] != s[s_right]) {
        if (t.erase(t_right, 1) != s) result = "No";
        break;
      }
    }
  }

  if (abs(s_n - t_n) > 1) result = "No";

  cout << result << endl;
}
