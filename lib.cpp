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

// =========== snippet ===========
// -- 素数判定
//   prefix: isPrime

int main() {
  // =========== method, struct ===========
  // Sieve of Eratosthenes
  // How to use:
  //  Sieve p(10)
  //  p.primes → [2, 3, 5, 7]
  struct Sieve {
    int n;
    vector<int> f, primes;
    Sieve(int n=1):n(n), f(n+1) {
      f[0] = f[1] = -1;
      for (ll i = 2; i <= n; ++i) {
        if (f[i]) continue;
        primes.push_back(i);
        f[i] = i;
        for (ll j = i*i; j <= n; j += i) {
          if (!f[j]) f[j] = i;
        }
      }
    }
  };

  // permutation
  // output↓
  // 1 2 3 
  // 1 3 2 
  // 2 1 3 
  // 2 3 1 
  // 3 1 2 
  // 3 2 1 
  vector<int> nums = {1,2,3};
  do {
    for (int n : nums) {
      cout << n << " ";
    }
    cout << endl;
  } while (next_permutation(nums.begin(), nums.end()));
}

