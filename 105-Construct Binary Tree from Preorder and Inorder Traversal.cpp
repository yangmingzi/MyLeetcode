//与上一题相同
//56ms，12.71%
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
//二刷，自己写，48 ms，39.20%
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n==0) return NULL;
        TreeNode* root = build(preorder,0,n-1,inorder,0,n-1);
        return root;
    }
    TreeNode* build(vector<int>& pre,int a1,int a2, vector<int>& in,int b1,int b2){
        TreeNode* root = new TreeNode(pre[a1]);
        int pos = 0;
        for(int i=b1;i<=b2;i++){
            if(in[i] == pre[a1]){
                pos = i;
                break;
            }
        }
        int leftLen  = pos - b1;
        int rightLen = b2 - pos;
        if(leftLen>0){root->left  = build(pre,a1+1,a1+leftLen,in,b1,b1+leftLen-1);}else{root->left=NULL;}
        if(rightLen>0){root->right = build(pre,a1+leftLen+1,a1+leftLen+rightLen-1,in,pos+1,pos+rightLen);}else{root->right=NULL;}
        return root;
    }
};