//根据BST中序遍历序列有序的性质判断，
//只要在中序遍历二叉树的代码基础上加上判断相邻元素关系的语句即可
/**
 * Definition for binary tree
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //注意题目要求是 less than和greater than;
        stack<TreeNode*> S;
        TreeNode *pre = NULL, *p = root;
        while(p || S.empty() == false)
        {
            while(p)
            {
                S.push(p);
                p = p->left;
            }
            if(S.empty() == false)
            {
                p = S.top();
                S.pop();
                if(pre && p->val <= pre->val)return false;
                pre = p;
                p = p->right;
            }
        }
        return true;
    }
};