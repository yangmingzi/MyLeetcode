/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
/*这一题可以完全采用和上一题一样的解法，只是需要注意dp的初始化值，和循环的起始值*/
//4ms,12.5%
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int>dp(n+1, 0);
        dp[1] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if(obstacleGrid[i-1][j-1] == 0)
                    dp[j] = dp[j] + dp[j-1];
                else dp[j] = 0;
        return dp[n];
    }
};

//二刷，自己写的，4ms,12.5%
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(int)*m*n);
        if(obstacleGrid[0][0] == 0){
            dp[0][0]=1;
        }else{
            dp[0][0] = 0;
        }
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]==1){dp[i][0] = 0;}
            else if(obstacleGrid[i-1][0] == 1){dp[i][0] = 0;}
            else{dp[i][0] = dp[i-1][0];}
        }
         for(int j=1;j<n;j++){
            if(obstacleGrid[0][j]==1){dp[0][j] = 0;}
            else if(obstacleGrid[0][j-1] == 1){dp[0][j] = 0;}
            else{dp[0][j] = dp[0][j-1];}
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else if(obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1]==1){
                    dp[i][j] = 0;
                }else if(obstacleGrid[i-1][j]==1&&obstacleGrid[i][j-1]==0){
                    dp[i][j] = dp[i][j-1];
                }else if(obstacleGrid[i-1][j]==0&&obstacleGrid[i][j-1]==1){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};