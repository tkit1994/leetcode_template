#ifdef LEETCODE
#include "leetcode.hpp"
using namespace std;
#endif
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == NULL)
      return 0;
    else {
      int left, right;
      left = maxDepth(root->left);
      right = maxDepth(root->right);
      return left > right ? left + 1 : right + 1;
    }
  }
};
#ifdef LEETCODE
int main(int, char **) {
  Solution s;
  auto result = createTree(NULL, {1, 2, 3, 4, 5, 6}, 0);
  printTree(result);
}
#endif