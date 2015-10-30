/*
题目是构造BST数的升序的iterator，实质是树的中序遍历。
题目中的第一个条件是O(h) memory，因为中序遍历的实现中，stack存的左节点，并且是从root开始到某点结束的左节点和结束点的右儿子的左后代的节点，着说明了stack的大小是O(h)的。
题目中的第二个条件是，平均时间复杂度是O(1)。由于对整棵树的N个节点做了hasNext()调用之后，也就是说，一共做了N次调用之后，都只把整棵树的N个节点的每个节点遍历了1遍，所以N次调用的时间复杂度是O(N)，平均下来每次就是O(1)。同理对于Next()的调用。
*/
/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
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
class BSTIterator {
private:
	stack<TreeNode*> s;
public:
    BSTIterator(TreeNode *root) {
        while(root){
        	s.push(root);
        	root=root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!s.empty());
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* cur = s.top();
        TreeNode* c_cur = cur;
        s.pop();
        cur = cur->right;
        while(cur!=NULL){
        	s.push(cur);
        	cur=cur->left;
        }
        return c_cur->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */