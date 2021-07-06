#ifdef LEETCODE
#include <dbg.h>

#include "leetcode.hpp"
using namespace std;
#endif // LEETCODE

class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> mp;
    for (auto n : nums1) {
      mp[n]++;
    }
    vector<int> result;
    for (auto n : nums2) {
      if (mp.find(n) != mp.end() && mp[n] != 0) {
        mp[n]--;
        result.push_back(n);
      }
    }
    return result;
  }
};
#ifdef LEETCODE
int main(int, char **) {
  vector<int> nums1 = {4, 9, 5}, nums2 = {9, 4, 8, 9, 4, 2};
  Solution s;
  auto res = s.intersect(nums1, nums2);
  fmt::print("{}", res);
}
#endif // LEETCODE