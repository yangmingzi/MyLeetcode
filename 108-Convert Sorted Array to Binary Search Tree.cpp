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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = num.size();
        if(len == 0)return NULL;
        return sortedArrayToBSTRecur(num, 0, len-1);
    }
    TreeNode *sortedArrayToBSTRecur(vector<int> &num, int istart, int iend)
    {
        if(istart > iend)return NULL;
        int middle = (istart+iend)/2;
        TreeNode *res = new TreeNode(num[middle]);
        res->left = sortedArrayToBSTRecur(num, istart, middle-1);
        res->right = sortedArrayToBSTRecur(num, middle+1, iend);
        return res;
    }
};