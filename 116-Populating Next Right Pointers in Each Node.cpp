//参考博客：http://www.cnblogs.com/higerzhang/p/4134025.html
/*
一个递归就搞定了，就是递归让每一个节点他的左右子树通过next链接，
直至到最后一层，然后递归左右节点，继续让他们的左右子树通过next链接。

*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

//每一层把left的right的next设置为right的left
void lr2rl(TreeLinkNode *root)
{
    if (!root) return;
    TreeLinkNode *lr = root -> left, *rl = root -> right;
    
    while(lr && rl)
    {
        lr -> next = rl;
        //可以想象一下从一个点垂直向下画线，链接和线对称的相邻的两个节点
        lr = lr -> right;
        rl = rl -> left;
    }
    lr2rl(root -> left);
    lr2rl(root -> right);
}
    void connect(TreeLinkNode *root) 
    {
        lr2rl(root);
    }
};