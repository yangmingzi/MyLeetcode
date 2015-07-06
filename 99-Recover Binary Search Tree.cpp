/*
首先我们最直观的的想法是中序遍历得到中序序列，平衡二叉树的中序序列是非递减有序的。
那么问题就转化成了在非递减有序序列中交换了两个数的位置，找出这两个数并恢复有序序列
首先找到第一个错误的数first，即第一个比它后缀要大的数
然后要找到第一个错误的数应该放置的位置（这就是第二个错误的数），即要找到第一个比first大的数的前驱，
这个前驱就是第一个错误的数应该放的位置，也就是第二个错误的数。
（注意一个特殊情况{0,1}，first为1，没有找到比first大的数，这是second就是最后一个数0）
还有一种非递归，空间复杂度为O(1)的方法，Morris Traverlsal。
见博客：http://www.cnblogs.com/TenosDoIt/p/3445682.html
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        TreeNode *pre = NULL, *first = NULL, *second = NULL;
        inorder(root, pre, first, second);
        if(first != NULL)
        {
            if(second == NULL)second = pre;//树{0,1}就可能出现这种情况
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }
    //pre是中序序列中当前节点的前驱，first、second分别是要找的两个乱序节点
    void inorder(TreeNode *root, TreeNode* &pre, TreeNode* &first, TreeNode* &second)
    {
        if(root == NULL)return;
        if(root->left)inorder(root->left, pre, first, second);
        if(pre != NULL)//前驱不为空
        {
            if(first == NULL && root->val < pre->val)//如果还没找到第一个
                first = pre;
            else if(first && root->val > first->val)//已经找到第一个
                {second = pre; return;}//两个错误位置都找到就退出
        }
        pre = root;
        if(root->right)inorder(root->right, pre, first, second);
    }
};