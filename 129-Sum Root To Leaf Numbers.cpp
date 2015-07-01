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
    void getSum(TreeNode* node,int res,int val){
        if(node->left==NULL && node->right==NULL){
            res+=val;
            return;
        }
        if(node->left!=NULL){
            getSum(node->left,res,val*10+node->left->val);
        }
        if(node->right!=NULL){
            res=res*10+val;
            getSum(node->right,res,val*10+node->right->val);
        }
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        int res=0;
        getSum(root,res,root->val);
        return res;
    }
};

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
    //sum记录所有路径之和，val记录单条路径代表的数字
    void getSum(TreeNode *root, int &sum, int val) {//int &sum
        if (root->right == NULL && root->left == NULL) {
            sum += val;
            return;
        } 
        if (root->left != NULL) {
            getSum(root->left, sum, val * 10 + root->left->val);
        }
        if (root->right != NULL) {
            getSum(root->right, sum, val * 10 + root->right->val);
        }
    }
    
    int sumNumbers(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int sum = 0;

        getSum(root, sum, root->val);
        return sum;
    }
};