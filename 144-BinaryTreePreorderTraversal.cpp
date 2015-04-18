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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ans;
        list<TreeNode*> node_list;
        if(root == NULL) return ans;
        node_list.push_front(root);
        while(!node_list.empty())
        {
            TreeNode *cur = node_list.front();
            node_list.pop_front();
            ans.push_back(cur -> val);
            if(cur -> right != NULL) node_list.push_front(cur -> right);
            if(cur -> left != NULL) node_list.push_front(cur -> left);
        }
        
        return ans;
    }
};