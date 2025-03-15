#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

int main() {
  string s;
  cin >> s;

  bool same = true;
  bool up = true;
  for (int i=0; i<s.size()-1; i++) {
    int curr = s[i] - '0';
    int next = s[i+1] - '0';
    int next_i = (curr+1)%10;
    if (curr != next) same = false;
    if (next != next_i) up = false;
  }
  cout << ((same || up) ? "Weak" : "Strong") << endl;
}
