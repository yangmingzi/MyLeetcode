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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result(0);
        
        if (root == NULL)
            return result;
        
        stack<TreeNode*> stk;
        TreeNode* p = root;
        
        while(!stk.empty() || p != NULL)
        {
            if (p != NULL)
            {
                stk.push(p);
                p = p->left;
            }
            else
            {
                p = stk.top();
                stk.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        
        return result;
    }
};