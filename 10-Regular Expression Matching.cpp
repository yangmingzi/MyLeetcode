/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
/*
接下来我们考虑如何优化brute force算法，熟悉动态规划的朋友可能发现了，其实这个思路已经很接近动态规划了。
动态规划基本思想就是把我们计算过的历史信息记录下来，等到要用到的时候就直接使用，不用重新计算。
在这个题里面，假设我们维护一个布尔数组res[i][j],
代表s的前i个字符和p的前j个字符是否匹配
(注意这里res的维度是s.length()+1,p.length()+1)。
递推公式跟上面类似，分三种种情况： 
(1)p[j+1]不是'*'。情况比较简单，
只要判断如果当前s的i和p的j上的字符一样（如果有p在j上的字符是'.',也是相同），
并且res[i][j]==true，则res[i+1][j+1]也为true，res[i+1][j+1]=false; 
(2)p[j+1]是'*'，但是p[j]!='.'。那么只要以下条件有一个满足即可对res[i+1][j+1]赋值为true： 
    1)res[i+1][j]为真（'*'只取前面字符一次）; 
    2)res[i+1][j-1]为真（'*'前面字符一次都不取，也就是忽略这两个字符）; 
    3)res[i][j+1] && s[i]==s[i-1] && s[i-1]==p[j-1](这种情况是相当于i从0到s.length()扫过来，
    如果p[j+1]对应的字符是‘*’那就意味着接下来的串就可以依次匹配下来，如果下面的字符一直重复，并且就是‘*’前面的那个字符）。 
(3)p[j+1]是'*'，并且p[j]=='.'。
因为".*"可以匹配任意字符串，所以在前面的res[i+1][j-1]或者res[i+1][j]中只要有i+1是true，
那么剩下的res[i+1][j+1],res[i+2][j+1],...,res[s.length()][j+1]就都是true了。 
这道题有个很重要的点，就是实现的时候外层循环应该是p,然后待匹配串s内层循环扫过来。
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.length()==0 && p.length()==0)
            return true;
        if(p.length()==0)
            return false;
        //boolean[][] res = new boolean[s.length()+1][p.length()+1];
        //这里我们要将res数组全部初始化为false，因为一开始会有不对称的情况，例如s='aaa',p='aa'，
        //而且这样后文只需要处理变成true的过程就可以了
        bool res[s.length()+1][p.length()+1];
        for(int i=0;i<=s.length();i++){
            for(int j=0;j<=p.length();j++){
                res[i][j]=false;
            }
        }
        res[0][0] = true;
        for(int j=0;j<p.length();j++)
        {
            if(p[j]=='*')
            {
                if(j>0 && res[0][j-1]) res[0][j+1]=true;
                if(j<1) continue;
                if(p[j-1]!='.')
                {
                    for(int i=0;i<s.length();i++)
                    {
                        if(res[i+1][j] || j>0&&res[i+1][j-1] 
                        || i>0 && j>0 && res[i][j+1]&&s[i]==s[i-1]&&s[i-1]==p[j-1])
                            res[i+1][j+1] = true;
                    }
                }
                else
                {
                    int i=0;
                    while(j>0 && i<s.length() && !res[i+1][j-1] && !res[i+1][j])
                        i++;
                    for(;i<s.length();i++)
                    {
                        res[i+1][j+1] = true;
                    }
                }
            }
            else
            {
                for(int i=0;i<s.length();i++)
                {
                    if(s[i]==p[j] || p[j]=='.')
                        res[i+1][j+1] = res[i][j];
                }
            }
        }
        return res[s.length()][p.length()];
    }
};