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
//为什么这样写是错的？递归在编程中的本质是什么？
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        res.push_back(root->val);
        if(root->left)preorderTraversal(root->left);
        if(root->right)preorderTraversal(root->right);
        return res;
    }
};
//递归的应该这样写
class Solution {
public:
     vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        res.clear();
        preorder(root);
        return res;
    }
    void preorder(TreeNode* root){
        if(root == NULL) return;
        res.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
};