/*
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
/*本题可扩展网络最大路径和，参考博客：http://www.cnblogs.com/TenosDoIt/p/3774804.html*/
/*
ACM之家里讲的很好，递归数组的大小是m*n，不应要(m+1)*(n+1)，二维递归+滚动数组
http://www.acmerblog.com/leetcode-solution-minimum-path-sum-6208.html
*/
/*
典型的动态规划问题。

设dp[i][j]表示从左上角到grid[i][j]的最小路径和。那么dp[i][j] = grid[i][j] + min( dp[i-1][j], dp[i][j-1] );
为了处理计算第一行和第一列的边界条件，我们令dp[i][j]表示从左上角到grid[i-1][j-1]的最小路径和，
最后dp[m][n]是我们所求的结果
注意到上面的方法中中dp[i][j] 只和上一行的dp[i-1][j]和上一列的dp[i][j-1]有关，
因此可以优化空间为O（n）（准确来讲空间复杂度可以是O（min（row,col）））    
*/
//28ms,28.13%
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row = grid.size(),col;
        if(row == 0)return 0;
        else col = grid[0].size();
        vector<int >dp(col+1, INT_MAX);
        dp[1] = 0;
        for(int i = 1; i <= row; i++)
            for(int j = 1; j <= col; j++)
                dp[j] = grid[i-1][j-1] + min(dp[j], dp[j-1]);
        return dp[col];
    }
};
//二刷，自己写，28ms,28.13%
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n = grid[0].size();
        int dp[m][n];
        memset(dp,INT_MAX,sizeof(int)*m*n);
        dp[0][0] = grid[0][0];
        for(int i=0;i<m;i++){
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }
        for(int j=0;j<n;j++){
            dp[0][j] = dp[0][j-1]+grid[0][j];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
//28ms,21.83%
// LeetCode, Minimum Path Sum
// 二维动规+滚动数组
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        int f[n];
        fill(f, f+n, INT_MAX); // 初始值是 INT_MAX，因为后面用了min函数。
        f[0] = 0;

        for (int i = 0; i < m; i++) {
            f[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                // 左边的f[j]，表示更新后的f[j]，与公式中的f[i[[j]对应
                // 右边的f[j]，表示老的f[j]，与公式中的f[i-1][j]对应
                f[j] = min(f[j - 1], f[j]) + grid[i][j];
            }
        }
        return f[n - 1];
    }
};
