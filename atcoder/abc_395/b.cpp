#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<char> > arr(n, vector<char>(n));

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      arr[i][j] = '0';
    }
  }

  for (int i=1; i<=n; i++) {
    int j = n + 1 - i;
    if (i <= j) {
      if (i % 2 == 0) {
        for (int a=0; a<n; a++) {
          for (int b=0; b<n; b++) {
            if (a >= i-1 && a <= j-1 && b >= i-1 && b <= j-1) {
              arr[a][b] = '.';
            }
          }
        }
      } else {
        for (int a=0; a<n; a++) {
          for (int b=0; b<n; b++) {
            if (a >= i-1 && a <= j-1 && b >= i-1 && b <= j-1) {
              arr[a][b] = '#';
            }
          }
        }
      }
    }
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }
}
