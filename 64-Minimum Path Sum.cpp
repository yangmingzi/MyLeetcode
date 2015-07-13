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