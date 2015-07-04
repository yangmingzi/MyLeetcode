//与上一题相同
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
    typedef vector<int>::iterator Iter;
    TreeNode* helper(Iter pstart,Iter pend,Iter istart,Iter iend){
        if(pstart==pend) return NULL;
        int rootval=*(pstart);
        Iter iterroot=find(istart,iend,rootval);
        TreeNode* root = new TreeNode(rootval);
        root->left=helper(pstart+1,pstart+1+(iterroot-istart),istart,iterroot);
        root->right=helper(pstart+1+(iterroot-istart),pend,iterroot+1,iend);
        return root;
    }
   
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }

};