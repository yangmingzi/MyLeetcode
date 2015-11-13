/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/
// 自己做的，10.06%，前列，4ms
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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear();
        if(root == NULL) return res;
        string tmp;
        tmp += to_string(root->val);
        bfs(root,tmp);
        return res;
    }
    void bfs(TreeNode* root,string& s){
        if(root->left==NULL && root->right==NULL) {res.push_back(s);return;}
        if(root->left!=NULL){
            string tmp = s;
            tmp+="->";
            tmp+=to_string(root->left->val);
            bfs(root->left,tmp);
        }
        if(root->right!=NULL){
            string tmp = s;
            tmp+="->";
            tmp+=to_string(root->right->val);
            bfs(root->right,tmp);
        }
    }
};