/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/
/*
好几种做法，参考博客：http://www.cnblogs.com/TenosDoIt/p/3704091.html
动态规划，算法1的递归解法中，其实我们计算了很多重复的子问题，比如计算uniquePaths(4, 5) 和 uniquePaths(5, 3)时都要计算子问题uniquePaths(3, 2)，再者由于uniquePaths(m, n) = uniquePaths(n, m)，这也使得许多子问题被重复计算了。
要保存子问题的状态，这样很自然的就想到了动态规划方法，设dp[i][j] = uniquePaths(i, j)， 那么动态规划方程为：

dp[i][j] = dp[i-1][j] + dp[i][j-1]
边界条件：dp[i][1] = 1, dp[1][j] = 1
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m+1, vector<int>(n+1, 1));
        for(int i = 2; i <= m; i++)
            for(int j = 2; j <= n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m][n];
    }
};