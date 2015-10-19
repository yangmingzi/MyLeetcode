/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

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
//自己做出来了，虽然很慢，4ms，击败4.65%，囧,不过和之前第一次做抄别人的答案一样的速度，还可以，哈哈
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
    vector<int> res;
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return NULL;
        dfs(root,0);
        int sum=0;
        for(int i=0;i<res.size();i++){
            sum+=res[i];
        }
        return sum;
    }
    void dfs(TreeNode* root,int curSum){
        curSum = curSum*10+root->val;
        if(root->left==NULL && root->right==NULL){
            res.push_back(curSum);
            return;
        }
        if(root->left){
            dfs(root->left,curSum);
        }
        if(root->right){
            dfs(root->right,curSum);
        }
    }
};