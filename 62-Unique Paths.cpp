/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/
/*
好几种做法，参考博客：http://www.cnblogs.com/TenosDoIt/p/3704091.html
最容易想到的是递归解法，uniquePaths(m, n) = uniquePaths(m, n-1) + uniquePaths(m-1, n), 递归结束条件是m或n等于1，这个方法oj超时了
动态规划，上面的递归解法中，其实我们计算了很多重复的子问题，比如计算uniquePaths(4, 5) 和 uniquePaths(5, 3)时都要计算子问题uniquePaths(3, 2)，再者由于uniquePaths(m, n) = uniquePaths(n, m)，这也使得许多子问题被重复计算了。
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

/*
上述过程其实是从左上角开始，逐行计算到达每个格子的路线数目，由递推公式可以看出，
到达当前格子的路线数目和两个格子有关：
1、上一行同列格子的路线数目；
2、同一行上一列格子的路线数目。
据此我们可以优化上面动态规划方法的空间:
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n+1, 1);
        for(int i = 2; i <= m; i++)
            for(int j = 2; j <= n; j++)
                dp[j] =  dp[j] + dp[j-1];
        return dp[n];
    }
};
*/
/*
其实这个和组合数有关，对于m*n的网格，从左上角走到右下角，总共需要走m+n-2步，其中必定有m-1步是朝右走，n-1步是朝下走，
那么这个问题的答案就是组合数：, 这里需要注意的是求组合数时防止乘法溢出 
class Solution {
public:
    int uniquePaths(int m, int n) {
        return combination(m+n-2, m-1);
    }
    
    int combination(int a, int b)
    {
        if(b > (a >> 1))b = a - b;
        long long res = 1;
        for(int i = 1; i <= b; i++)
            res = res * (a - i + 1) / i;
        return res;
    }
};
*/


//二刷，自己。0ms,7.42%
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        memset(dp,0,sizeof(int)*m*n);
        dp[0][0]=1;
        for(int i=1;i<m;i++){dp[i][0] = 1;}
        for(int j=1;j<n;j++){dp[0][j] = 1;}
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] =dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
//滚动数组，速度和上面相同
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n+1, 1);
        for(int i = 2; i <= m; i++)
            for(int j = 2; j <= n; j++)
                dp[j] =  dp[j] + dp[j-1];
        return dp[n];
    }
};