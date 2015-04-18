//相比于前序遍历，后续遍历思维上难度要大些，前序遍历是通过一个stack，首先压入父亲结点，然后弹出父亲结点，并输出它的value，之后压人其右儿子，左儿子即可。
//然而后序遍历结点的访问顺序是：左儿子 -> 右儿子 -> 自己。那么一个结点需要两种情况下才能够输出：
//第一，它已经是叶子结点；
//第二，它不是叶子结点，但是它的儿子已经输出过。
//那么基于此我们只需要记录一下当前输出的结点即可。
//对于一个新的结点，如果它不是叶子结点，儿子也没有访问，那么就需要将它的右儿子，左儿子压入。
//如果它满足输出条件，则输出它，并记录下当前输出结点。输出在stack为空时结束。
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        list<TreeNode*> node_list;
        if(root == NULL) return ans;
        node_list.push_front(root);
        TreeNode *head = root;
        while(!node_list.empty())
        {
            TreeNode *cur = node_list.front();
            
            if(cur -> right == head || cur -> left == head || ((cur -> right == NULL) && (cur -> left == NULL)))
            {
                node_list.pop_front();
                ans.push_back(cur -> val);
                head = cur;
            }
            else
            {
                if(cur -> right != NULL) node_list.push_front(cur -> right);
                if(cur -> left != NULL) node_list.push_front(cur -> left);
            }
        }
    
    }
};
