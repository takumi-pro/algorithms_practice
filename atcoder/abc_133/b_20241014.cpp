#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n,d;
  cin >> n >> d;
  vector<vector<int> > x(n, vector<int>(d));
  for(int i=0; i<n; i++) {
    for(int j=0; j<d; j++) cin >> x[i][j];
  }

  int ans = 0;
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      int sum = 0;
      for (int k=0; k<d; k++) {
        int s = x[i][k] - x[j][k];
        sum += s * s;
      }
      int sq = sqrt(sum);
      if (sum == sq * sq) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
