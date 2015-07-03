//深搜DFS
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
    //为什么&res,path?
    //答：res每次更新都要保证在同一块内存地址，而Path由于路径不同，所以不是在同一块内存地址，每次迭代需要复制成新的path
    void getPath(TreeNode *root, int sum, vector<vector<int> > &res, vector<int> path) {
        if (root == NULL) {
            return;
        }
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                res.push_back(path);
            }
            return;
        }
        getPath(root->left, sum - root->val, res, path);
        getPath(root->right, sum - root->val, res, path);
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> path;
        getPath(root, sum, res, path);
        return res;
    }
};