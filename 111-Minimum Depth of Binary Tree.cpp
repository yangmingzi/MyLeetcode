//DFS
//为了保证res值在被修改的时候始终指向一处内存，故dfs中参数为&res
class Solution {
public:
    int minDepth(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == NULL)return 0;
        int res = INT_MAX;
        dfs(root, 1, res);
        return res;
    }
    void dfs(TreeNode *root, int depth, int &res)
    {
        if(root->left == NULL && root->right == NULL && res > depth)
            {res = depth; return;}
        if(root->left)
            dfs(root->left, depth+1, res);
        if(root->right)
            dfs(root->right, depth+1, res);
    }
};

