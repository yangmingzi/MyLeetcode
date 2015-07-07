//递归解法，判断左右两颗子树是否对称，
//只要两颗子树的根节点值相同，并且左边子树的左子树和右边子树饿右子树对称 且 左边子树的右子树和右边子树的左子树对称         
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
    bool isSymmetric(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == NULL)return true;
        return isSymmetricRecur(root->left, root->right);
    }
    bool isSymmetricRecur(TreeNode *root1, TreeNode *root2)
    {
        if(root1 != NULL && root2 != NULL)
        {
            if(root1->val == root2->val && 
                isSymmetricRecur(root1->left, root2->right) &&
                isSymmetricRecur(root1->right, root2->left))
                return true;
            else return false;
            
        }
        else if(root1 != NULL || root2 != NULL)
            return false;
        else return true;
        
    }
};