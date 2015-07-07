class Solution {
public:
    int numDecodings(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //注意处理字符串中字符为0的情况
        int len = s.size();
        if(len == 0)return 0;
        int dp[len+1];//dp[i]表示s[0...i-1]的解码方法数目
        dp[0] = 1;
        if(s[0] != '0')dp[1] = 1;
        else dp[1] = 0;
        for(int i = 2; i <= len; i++)
        {
            if(s[i-1] != '0')
                dp[i] = dp[i-1];
            else dp[i] = 0;
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))
                dp[i] += dp[i-2];
        }
        return dp[len];
    }
};