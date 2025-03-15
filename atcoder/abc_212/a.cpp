#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  string res = "Alloy";
  if (0<a && b==0) res = "Gold";
  if (a==0 && 0<b) res = "Silver";
  cout << res << endl;
}
