/*
首先肯定的是要对树进行层序遍历，但是相邻两层的元素遍历顺序是相反的，因此传统的非递归遍历方法用一个队列肯定是无法实现。
我们用两个栈来实现，同一层元素都在同一个栈中，相邻的两层元素放在不同的栈中，
比如第一层元素放在第一个栈，那么第二层就放在第二个栈，第三层就放在第三个栈......
如果某一层元素是从左往右遍历的，那么这层元素的孩子节点入栈顺序就是先左孩子后右孩子，
相反如果某一层元素是从右往左遍历的，入栈顺序就是先右孩子后左孩子。
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> >res;
        if(root == NULL)return res;
        stack<TreeNode*> S,S2;
        S.push(root);
        bool isS = true;
        vector<int>tmpres;
        while(S.empty() == false || S2.empty() == false)
        {
            TreeNode *p;
            if(isS)
            {
                
                p = S.top();
                S.pop();
                tmpres.push_back(p->val);
                if(p->left)S2.push(p->left);
                if(p->right)S2.push(p->right);
                if(S.empty() == true)
                {
                    res.push_back(tmpres);
                    tmpres.clear();
                    isS = false;
                }
            }
            else
            {
                p = S2.top();
                S2.pop();
                tmpres.push_back(p->val);
                if(p->right)S.push(p->right);
                if(p->left)S.push(p->left);
                if(S2.empty() == true)
                {
                    res.push_back(tmpres);
                    tmpres.clear();
                    isS = true;
                }
            }
        }
        return res;
    }
};