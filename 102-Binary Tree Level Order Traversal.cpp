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
	vector<vector<int>> res;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {       
        levelTra(root,0);
        return res;
    }
    void levelTra(TreeNode* root,int level){
    	if(root==NULL) return;
    	if(level==res.size()){
    		vector<int> a;
    		res.push_back(a);
    	}
    	res[level].push_back(root->val);   	
    	if(root->left) levelTra(root->left,level+1);
    	if(root->right) levelTra(root->right,level+1);
    }
};