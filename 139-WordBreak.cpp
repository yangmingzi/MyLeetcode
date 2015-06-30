/*
参照官网用的方法，DP可解决问题，即将源字符串从开始到结尾，分解成各个子串进行操作，
对于这类字符串组合问题，需要掌握类似状态转移方程，代码如下：
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int nsize=s.size();
        int i=0,j=0;
        bool *dp = new bool[nsize];
        memset(dp,false,sizeof(dp));
        
        for(i=0;i<nsize;++i)
        {
            dp[i] = ((dict.find(s.substr(0,i+1))!=dict.end())?true:false);
            if(dp[i])
                continue;
            else
            {
                for(j=0;j<i;++j)
                {
                    if(dp[j])
                    {
                        dp[i] = ((dict.find(s.substr(j+1,i-j))!=dict.end())?true:false) | dp[i];
                    }
                }
            }
        }
        return dp[nsize-1];
        delete []dp;
    }
};