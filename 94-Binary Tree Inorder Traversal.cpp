/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Hide Tags Tree Hash Table Stack
Hide Similar Problems (M) Validate Binary Search Tree (M) Binary Tree Preorder Traversal (H) Binary Tree Postorder Traversal (M) Binary Search Tree Iterator (M) Kth Smallest Element in a BST

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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result(0);
        
        if (root == NULL)
            return result;
        
        stack<TreeNode*> stk;
        TreeNode* p = root;
        
        while(!stk.empty() || p != NULL)
        {
            if (p != NULL)
            {
                stk.push(p);
                p = p->left;
            }
            else
            {
                p = stk.top();
                stk.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        
        return result;
    }
};
//Morris算法（不用递归，不用栈,O(1)）
//以前一直觉得很难理解的算法，在2015年8月9日和冕神在百度，自己看了会儿书就明白了，纪念一下#参加活动的意义#。
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        TreeNode *p=root;
        TreeNode *tmp;
        while(p){
            if(p->left==NULL){
                res.push_back(p->val);
                p=p->right;
            }else{
                tmp=p->left;
                while(tmp->right!=NULL && tmp->right!=p){tmp=tmp->right;}
                if(tmp->right==NULL){
                    tmp->right=p;
                    p=p->left;
                }else{
                    res.push_back(p->val);
                    tmp->right=NULL;
                    p=p->right;
                }
            }
        }
        return res;
    }
};