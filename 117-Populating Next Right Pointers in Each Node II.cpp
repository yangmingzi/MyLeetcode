/*
不完全二叉树的链接
父节点调度左节点的链接
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
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode *p=root->next;
        TreeLinkNode *sonNext=NULL;//必须初始化为NULL
        while(p){
            if(p->left){
                sonNext = p->left;
                break;
            }
            else if(p->right){
                sonNext=p->right;
                break;
            }
            p=p->next;
        }
        if(root->right){
            root->right->next=sonNext;
            if(root->left){
                root->left->next=root->right;
            }
        }else if(root->left){
            root->left->next=sonNext;
        }
        
        //为什么一定要先处理右子树，在处理左子树？
        connect(root->right);
        connect(root->left);
    }
};