#ifdef LEETCODE
#include <dbg.h>

#include "leetcode.hpp"
using namespace std;
#endif

class Solution {
public:
  string addStrings(string num1, string num2) {
    string res = "";
    int carry = 0;
    int i = num1.length() - 1, j = num2.length() - 1;
    while (i >= 0 || j >= 0 || carry != 0) {
      int x = i >= 0 ? num1[i] - '0' : 0;
      int y = j >= 0 ? num2[j] - '0' : 0;
      int sum = x + y + carry;
      res.push_back(sum % 10 + '0');
      carry = sum / 10;
      i--;
      j--;
    }
    reverse(res.begin(), res.end());

    return res;
  }
};
#ifdef LEETCODE
int main(int, char **) {
  Solution s;
  auto res = s.addStrings("1234", "789");
  fmt::print("{}\n", res);
  res = s.addStrings("1", "9");
  fmt::print("{}\n", res);
}
#endif