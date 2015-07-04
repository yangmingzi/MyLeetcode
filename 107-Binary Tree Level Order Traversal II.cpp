//参考了Discussion中stellari的做法，递归进行层次遍历，并将每个level对应于相应的vector。
//可参照此博客：http://www.cnblogs.com/ganganloveu/p/3843470.html
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //if(root==NULL) return NULL;不能加这句，返回类型不对
        levelTra(root,0);
        return vector<vector<int>> (res.rbegin(),res.rend());
    }
    void  levelTra(TreeNode *root,int level){
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