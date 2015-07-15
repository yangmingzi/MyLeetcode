/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants
(where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/
/*
本题乍一看不算简单，其实，只要考虑到BST的特性，还是可以比较容易的得到答案，
首先设定LCA为root，
(1)如果root->val比p,q值都小，LCA要设定为root->right
(2)如果root->val比p,q都大，LCA要设定为root->left
(3)如果root->val在p,q之间，则结束循环，LCA得到最终值：root

用recursive运行上面三步，如果遇到(3)跳出，返回最终值
*/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val < p->val and root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (root->val > p->val and root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else {
            return root;
        }
    }
};