#pragma once
#include <algorithm>
#include <fmt/ranges.h>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL){};
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void printList(ListNode *node) {
  while (node != NULL) {
    fmt::print("{} -> ", node->val);
    node = node->next;
  }
  fmt::print("NULL\n");
}
ListNode *createList(std::vector<int> vec) {
  ListNode *head = new ListNode(0);
  ListNode *current = head;
  for (auto i : vec) {
    current->next = new ListNode(i);
    current = current->next;
  }
  return head->next;
}

TreeNode *createTree(TreeNode *root, std::vector<int> vec, int i) {

  if (i < vec.size()) {
    TreeNode *tmp = new TreeNode(vec[i]);
    root = tmp;
    root->left = createTree(root->left, vec, i * 2 + 1);
    root->right = createTree(root->right, vec, i * 2 + 2);
  }
  return root;
}

void printTree(TreeNode *root) {
  if (root != NULL) {
    fmt::print("{} ", root->val);
    printTree(root->left);
    printTree(root->right);
  }
}