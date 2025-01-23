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
  int result = 0;
  int zero_count = 0;
  for (int i=0; i<s.size(); i++) {
    if (s[i] == '0') {
      if (zero_count == 0) result++, zero_count++;
      else if (zero_count == 1) zero_count = 0;
      else if (zero_count == 1 && i == s.size()-2) result++;
    }
    if (s[i] != '0') {
      result++;
      zero_count = 0;
    }
  }
  cout << result << endl;
}
