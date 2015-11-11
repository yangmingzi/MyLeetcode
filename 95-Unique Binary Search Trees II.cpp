/*
按照上一题的思路，我们不仅仅要保存i个节点对应的BST树的数目，还要保存所有的BST树，
而且1、2、3和4、5、6虽然对应的BST数目和结构一样，但是BST树是不一样的，因为节点值不同。
我们用数组btrees[i][j][]保存节点i, i+1,...j-1,j构成的所有二叉树，
从节点数目为1的的二叉树开始自底向上最后求得节点数目为n的所有二叉树                         
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
    vector<TreeNode *> generateTrees(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<vector<TreeNode*> > > btrees(n+2, vector<vector<TreeNode*> >(n+2, vector<TreeNode*>()));
        for(int i = 1; i <= n+1; i++)
            btrees[i][i-1].push_back(NULL); //为了下面处理btrees[i][j]时 i > j的边界情况
        for(int k = 1; k <= n; k++)//k表示节点数目
            for(int i = 1; i <= n-k+1; i++)//i表示起始节点
            {
                for(int rootval = i; rootval <= k+i-1; rootval++)
                {//求[i,i+1,...i+k-1]序列对应的所有BST树
                    for(int m = 0; m < btrees[i][rootval-1].size(); m++)//左子树
                        for(int n = 0; n < btrees[rootval+1][k+i-1].size(); n++)//右子树
                        {
                            TreeNode *root = new TreeNode(rootval);
                            root->left = btrees[i][rootval-1][m];//当i=1时，我们会用到btrees[0]
                            root->right = btrees[rootval+1][k+i-1][n];//当i=n是，我们会用到btrees[n+1]。所以初始的向量size是n+2
                            btrees[i][k+i-1].push_back(root);
                        }
                }
            }
        return btrees[1][n];
    }
};
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return createTree(1,n);
    }
    vector<TreeNode*> createTree(int start,int end){
        vector<TreeNode*> res;
        if(start>end){
            res.push_back(NULL);
            return res;
        }
        for(int k=start;k<=end;k++){
             vector<TreeNode*> left  = createTree(start,k-1);
             vector<TreeNode*> right = createTree(k+1,end);
            for(int i=0;i<left.size();i++){
                for(int j=0;j<right.size();j++){
                    TreeNode* root = new TreeNode(k);
                    root->left  = left[i];
                    root->right = right[j];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};