/*
动态规划，设dp[i][j]是从字符串S[0...i]中删除几个字符得到字符串T[0...j]的不同的删除方法种类，
有上面递归的分析可知，动态规划方程如下
如果S[i] = T[j], dp[i][j] = dp[i-1][j-1]+dp[i-1][j]
如果S[i] 不等于 T[j], dp[i][j] = dp[i-1][j]
初始条件：当T为空字符串时，从任意的S删除几个字符得到T的方法为1
*/
class Solution {
public:
    int numDistinct(string S, string T) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int lens = S.length(), lent = T.length();
        if(lent == 0)return 1;
        else if(lens == 0)return 0;
        int dp[lens+1][lent+1];
        memset(dp, 0 , sizeof(dp));
        for(int i = 0; i <= lens; i++)dp[i][0] = 1;
        for(int i = 1; i <= lens; i++)
        {
            for(int j = 1; j <= lent; j++)
            {
                if(S[i-1] == T[j-1])
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[lens][lent];
    }
};