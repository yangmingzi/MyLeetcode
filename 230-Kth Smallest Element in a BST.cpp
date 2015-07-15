/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and
 you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
/*
This link suggests a concise C++ recursive solution. https://leetcode.com/discuss/43267/4-lines-in-c
The original code may be hard to understand at first and I have rewritten the code below.
 You may need to run some examples with it to see how it works.
*/
 class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return smallest(root, k);
    }
private:
    int smallest(TreeNode* node, int& k) {
        if (!node) return -1;
        int val = smallest(node -> left, k);
        if (!k) return val;
        if (!--k) return node -> val;
        return smallest(node -> right, k);
    }
};
/*
The same author also posts three solutions which is more space-efficient in this link. 
 All of them reduce the O(n) space of the above code to O(k) space by using some nice data structures.

Personally I really love the soltuion using deque and I have rewritten it below.
https://leetcode.com/discuss/43299/o-k-space-o-n-time-10-short-lines-3-solutions
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = root;
        deque<TreeNode*> nodes;
        while (true) {
            while (node) {
                nodes.push_front(node);
                if (nodes.size() > k)
                    nodes.pop_back();
                node = node -> left;
            }
            node = nodes.front();
            nodes.pop_front();
            if (!--k) return node -> val;
            node = node -> right;
        }
    }
};