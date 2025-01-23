#include <vector>
#include <iostream>
using namespace std;

int main() {
  int n,x;
  cin >> n >> x;
  vector<int> l(n);
  for(int i=0; i<n; i++) cin >> l[i];

  int count = 1;
  int d = 0;
  int i=1;
  while (d <= x && i <= n) {
    d += l[i-1];
    if (d > x) {
      cout << count << endl;
      return 0;
    }
    count++;
    i++;
  }

  cout << count << endl;
  return 0;
}
