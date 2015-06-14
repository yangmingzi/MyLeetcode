/*
完整二叉树
两种情况：最后一层满，最后一层不满。
递归的方法比较好理解。
参考如下两个网址
http://www.cnblogs.com/easonliu/p/4556487.html
http://bookshadow.com/weblog/2015/06/06/leetcode-count-complete-tree-nodes/
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreedNode *l = root,*r=root;
        int num_l=0,num_r=0;//此处必须初始化,否则Time Limit Exceeded
        while(l) {num_l++;l=l->left;}//不可写成while(l->left)，对于仅有根节点的情况，以及底下可以用pow(2,num_l),而不是pow(2,num_l+1)
        while(r){nul_r++;r=r->right;}
        if(num_l==num_r) return pow(2,num_l)-1;
        return countNodes(root->left)+countNodes(root->right)+1;

    }
};
