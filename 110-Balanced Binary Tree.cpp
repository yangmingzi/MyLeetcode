/**
 * Definition for binary tree
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
平衡二叉树(Balanced Binary Tree)又被称为AVL树(有别于AVL算法)，
且具有以下性质:它是一 棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。
构造与调整方法 平衡二叉树的常用算法有红黑树、AVL、Treap等。
*/
//判断一颗二叉树是否是平衡的，dfs递归求解，递归的过程中顺便求得树的高度       
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == NULL)return true;
        if(height(root) == -1)return false;
        else return true;
    }
    //若root是平衡树，那么返回树的高度，否则返回-1
    int height(TreeNode *root)
    {
        //if(root==NULL) return 0;此句可有可无，因为只有不为空才会进入height函数
        if(root->left == NULL && root->right == NULL)return 1;//最小情形返回值
        //中间递归过程
        int leftHeight = 0, rightHeight = 0;
        if(root->left)
            leftHeight = height(root->left);
        if(leftHeight == -1)return -1;
        if(root->right)
            rightHeight = height(root->right);
        if(rightHeight == -1)return -1;
        if(abs(leftHeight-rightHeight) > 1)return -1;
        return 1+max(leftHeight, rightHeight);//中间过程返回值
    }
};