//和111题求二叉树最小高度是一样的做法
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int res=INT_MIN;       
        helper(root,1,res);
        return res;   
    }
    void helper(TreeNode *root,int depth,int &res){        
        if(root->left==NULL && root->right==NULL&&depth>res){res=depth;return;}
        int ld=0,rd=0;    
        if(root->left)    
            ld=helper(root->left,depth+1,res);
        if(root->right)
            rd=helper(root->left,depth+1,res);
    }
};
//二刷，代码简洁
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};