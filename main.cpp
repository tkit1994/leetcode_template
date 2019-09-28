#ifdef LEETCODE
#include <dbg.h>
#include "leetcode.hpp"
using namespace std;
#endif

class Solution {
// dynamic programming with cache
private:
  vector<bool> dp;
  int max;

public:
  Solution() {
    this->max = 2;
    vector<bool> vec(1001);
    vec[0] = false;
    vec[1] = false;
    vec[2] = true;
    this->dp = vec;
  };
  bool divisorGame(int N) {
    if (N <= this->max)
      return this->dp[N];

    for (int k = this->max + 1; k <= N; k++) {
      for (int i = 1; i < k / 2; i++) {
        if (k % i == 0 && !dp[k - i]) {
          dp[k] = true;
          break;
        }
        dp[k] = false;
      }
    }
    this->max = N;
    return dp[N];
  }
}

;
#ifdef LEETCODE
int main(int, char **) {
  Solution s;
  auto result1 = s.divisorGame(999);
  fmt::print("{}\n", result1);
  auto result2 = s.divisorGame(333);
  fmt::print("{}\n", result2);
}
#endif