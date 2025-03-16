#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

#define INF 1010000000

using namespace std;

int main() {
  float x; cin >> x;
  int res = 3;
  if (x >= 38) res = 1;
  else if (x >= 37.5 && x < 38) res = 2;
  cout << res << endl; 
}
