#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  int count = 0;
  cin >> n;
  vector<int> p(n);
  for(int i=0; i<n; i++) cin >> p[i];
  for(int i=0; i<n-2; i++) {
    int maximum = max(max(p[i], p[i+1]), p[i+2]);
    int minimum = min(min(p[i], p[i+1]), p[i+2]);
    if (p[i+1] != maximum && p[i+1] != minimum) count++;
  }
  cout << count << endl;
  return 0;
}
