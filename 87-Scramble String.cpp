//参加博客：http://www.cnblogs.com/TenosDoIt/p/3452004.html
/*
递归解法有很多重复子问题，比如s2 = rgeat, s1 = great 
当我们选择分割点为0时，
要解决子问题 isScramble(reat, geat)，再对该子问题选择分割点0时，要解决子问题 isScramble(eat,eat)；
而当我们第一步选择1作为分割点时，
也要解决子问题 isScramble(eat,eat)。相同的子问题isScramble(eat,eat)就要解决2次。

动态规划用数组来保存子问题，
设dp[k][i][j]表示s2从j开始长度为k的子串是否可以由s1从i开始长度为k的子串转换而成，那么动态规划方程如下

初始条件：dp[1][i][j] = (s1[i] == s2[j] ? true : false)
 dp[k][i][j] = ( dp[divlen][i][j] && dp[k-divlen][i+divlen][j+divlen])||(dp[divlen][i][j+k-divlen] && dp[k-divlen][i+divlen][j] ) 
 (divlen = 1,2,3...k-1, 它表示子串分割点到子串起始端的距离) ，只要一个子问题返回真，就可以停止计算
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        //动态规划解法
        if(s1.size() != s2.size())return false;
        const int len = s1.size();
        //dp[k][i][j]表示s2从j开始长度为k的子串是否可以由s1从i开始长度为k的子串转换而成
        bool dp[len+1][len][len];
        //初始化长度为1的子串的dp值
        for(int i = 0; i <= len-1; i++)
            for(int j = 0; j <= len-1; j++)
                dp[1][i][j] = s1[i] == s2[j] ? true : false;
        for(int k = 2; k <= len; k++)//子串的长度
            for(int i = 0; i <= len-k; i++)//s1的起始位置
                for(int j = 0; j <= len-k; j++)//s2的起始位置
                {
                    dp[k][i][j] = false;
                    //divlen表示两个子串分割点到子串起始端的距离
                    for(int divlen = 1; divlen < k && !dp[k][i][j]; divlen++)
                        dp[k][i][j] = (dp[divlen][i][j] && dp[k-divlen][i+divlen][j+divlen])
                            || (dp[divlen][i][j+k-divlen] && dp[k-divlen][i+divlen][j]);
                }
        return dp[len][0][0];
    }
};