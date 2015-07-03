//DFS
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) { 
            return false;
        }
        if (root->left == NULL && root->right == NULL) {
            return root->val == sum;
        }
        bool flag1 = hasPathSum(root->left, sum - root->val);
        bool flag2 = hasPathSum(root->right, sum - root->val);
        return flag1 || flag2;
    }
};