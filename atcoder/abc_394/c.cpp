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
  int n = s.size();
  int right = n-1;
  for (int left = n-1; left>=0; left--) {
    if (s[left] == 'W' && s[right] == 'A') {
      s[left] = 'A';
      s[right] = 'C';
      right--;
    }
    if (right - left == 1) {
      right--;
    }
  }
  cout << s;
}
