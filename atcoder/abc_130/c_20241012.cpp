#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  long long W, H, x,y;
  cin >> W >> H >> x >> y;
  
  double s = (W*H)/2.0;
  int sp = 0;
  if (2*x == W && 2*y == H) sp = 1;

  cout << fixed << setprecision(6) << s << " " << sp << endl;
  return 0;
}

