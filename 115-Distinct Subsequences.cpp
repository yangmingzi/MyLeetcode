/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

Hide Tags Dynamic Programming String

*/
/*
动态规划，设dp[i][j]是从字符串S[0...i]中删除几个字符得到字符串T[0...j]的不同的删除方法种类，
有上面递归的分析可知，动态规划方程如下
如果S[i]等于T[j], dp[i][j] = dp[i-1][j-1]+dp[i-1][j]
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
                if(S[i-1] == T[j-1])//因为dp方程要依托于i-1和j-1,所以dp的size是(n+1)*(m+1)
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];//j的变化趋势一定是单调不减的
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[lens][lent];
    }
};
//8ms！！！
class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int record[200];
        for(int i=1; i<200; i++)
        record[i]=0;
        
        record[0]=1;
        for(int i=1; i<=S.size(); i++)
        for(int j=T.size(); j>=1; j--)
        {
            if(S[i-1]==T[j-1])
            record[j]+=record[j-1];
        }
        
        return record[T.size()];
    }
};