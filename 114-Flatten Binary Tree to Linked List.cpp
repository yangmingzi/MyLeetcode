//前序遍历，谦虚遍历
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode *root, TreeNode *&pre) {
        if (root == NULL) return;
        if (pre != NULL) {
            pre->left = NULL;
            pre->right = root;
        }
        pre = root;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        if (left != NULL) {
            helper(left, pre);
        }
        if (right != NULL) {
            helper(right, pre);
        }
    }
    void flatten(TreeNode *root) {
        TreeNode *pre = NULL;
        helper(root, pre);
    }
};

//非递归解法：
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == NULL) return;
        TreeNode *cur = root, *pre = NULL;
        while (cur != NULL) {
            if (cur->left != NULL) {
                pre = cur->left;
                while (pre->right) pre = pre->right;
                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};

/*
Given

         1
        / \
       2   5
      / \   \
     3   4   6
 The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
[解题思路]

         1
          \
           2
          / \
         3   4
              \
               5
                \
                 6
对root的左子树进行处理，将左子树的根节点和左子树的右子树插入右子树中
接下来对节点2进行处理，同样将2的左子树插入右子树中
*/