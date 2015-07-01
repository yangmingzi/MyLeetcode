//递归
//
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
		//三种情况，巧妙的运用逻辑运算符
        if(p&&q){
			//递归
            if(p->val==q->val && (isSameTree(p->left,q->left))&&isSameTree(p->right,q->right))
                return true;
            else return false;//不加这句也可以AC,为什么？？？
            }
        else if(p||q)
            return false;
        else return true;
        }
};