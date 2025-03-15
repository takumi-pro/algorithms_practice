#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

int main() {
  // vector<char> S(100);
  string s;
  cin >> s;
  for (auto c : s) {
    if (c != '2') continue;
    cout << '2';
  }
}
