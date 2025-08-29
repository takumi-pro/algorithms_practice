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
using vvi = vector<vector<int> >;

int main() {
  string S; cin >> S;
  if (S == "red") cout << "SSS" << endl;
  if (S == "blue") cout << "FFF" << endl;
  if (S == "green") cout << "MMM" << endl;
  if (S != "red" && S != "blue" && S != "green") cout << "Unknown" << endl;
}

