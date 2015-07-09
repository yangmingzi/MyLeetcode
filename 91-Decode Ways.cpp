/*
需要注意的是，如果序列中有不能匹配的0，那么解码方法是0，
比如序列012 、100（第二个0可以和1组成10，第三个0不能匹配）。
递归的解法很容易，但是大集合会超时。
转换成动态规划的方法，假设dp[i]表示序列s[0...i-1]的解码数目，动态规划方程如下：                                                                                                                                                               本文地址

初始条件：dp[0] = 1, dp[1] = (s[0] == '0') ? 0 : 1
dp[i] = ( s[i-1] == 0 ? 0 : dp[i-1] ) + ( s[i-2,i-1]可以表示字母 ？ dp[i-2] : 0 )， 
其中第一个分量是把s[0...i-1]末尾一个数字当做一个字母来考虑，
第二个分量是把s[0...i-1]末尾两个数字当做一个字母来考虑
*/
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