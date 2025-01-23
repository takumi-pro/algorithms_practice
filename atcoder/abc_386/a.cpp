#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  map<int, int> m;
  m[a]++;
  m[b]++;
  m[c]++;
  m[d]++;

  if (m.size() == 2) {
    if (m.begin()->second == 3 && m.rbegin()->second == 1 ||
        m.begin()->second == 2 && m.rbegin()->second == 2 ||
        m.begin()->second == 1 && m.rbegin()->second == 3
    ) {
      cout << "Yes" << endl;
      return 0;
      }
  }
  cout << "No" << endl;
}
