/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/
/*
后序序列的最后一个元素就是树根，然后在中序序列中找到这个元素（由于题目保证没有相同的元素，因此可以唯一找到），
中序序列中这个元素的左边就是左子树的中序，右边就是右子树的中序，
然后根据刚才中序序列中左右子树的元素个数可以在后序序列中找到左右子树的后序序列，然后递归的求解即可
*/
//56ms,11.32%
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
    typedef vector<int>::iterator Iter;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return buildTreeRecur(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    TreeNode *buildTreeRecur(Iter istart, Iter iend, Iter pstart, Iter pend)
    {
        if(istart == iend)return NULL;
        int rootval = *(pend-1);
        Iter iterroot = find(istart, iend, rootval);
        TreeNode *res = new TreeNode(rootval);
        res->left = buildTreeRecur(istart, iterroot, pstart, pstart+(iterroot-istart));
        res->right = buildTreeRecur(iterroot+1, iend, pstart+(iterroot-istart), pend-1);
        //或者res->right=helper(root+1,iend,pend-(iend-root)+1,pend-1);
        return res;
    }
};

//二刷，36ms，57.44%
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       if(inorder.size()==0) return NULL;
       TreeNode * root = createTree(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
       return root;
    }
    TreeNode* createTree(vector<int>& inorder, vector<int>& postorder,int inBeg,int inEnd,int poBeg,int poEnd){
         if(inBeg>inEnd) return NULL;
         TreeNode* root = new TreeNode(postorder[poEnd]);
         int idx;
         for(int i=inBeg;i<=inEnd;i++){
             if(inorder[i] == root->val){
                 idx = i;
                 break;
             }
         }
         int len = idx - inBeg;
         root->left  = createTree(inorder,postorder,inBeg,idx-1,poBeg,poBeg+len-1);
         root->right = createTree(inorder,postorder,idx+1,inEnd,poBeg+len,poEnd-1);
         return root;
    } 
};