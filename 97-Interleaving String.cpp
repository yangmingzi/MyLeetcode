/*
动态规划解法：根据递归的思想，我们一刻如下使用动态规划解此题。
设dp[i][j]表示s1[0...i-1]和s2[0...j-1]能否组合成s3[0....i+j-1]，动态规划方程如下                                                                               本文地址

dp[i][j] = (dp[i][j-1] ==true && s3[i+j-1] == s2[j-1]) || (dp[i-1][j] == true && s3[i-1+j] == s1[i-1])
初始条件：if(s1[0] == s3[0])dp[1][0] = true  ，  if(s2[0] == s3[0])dp[0][1] = true; 其他值均为false
*/
//0ms，80.95%
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.    
        const int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len1 == 0)return s2 == s3;
        else if(len2 == 0)return s1 == s3;
        // dp[i][j]表示s1[0...i-1]和s2[0...j-1]能否组合成s3[0....i+j-1]
        bool dp[len1+1][len2+1];
        memset(dp, 0, sizeof(dp));
        if(len3 != 0)
        {
            if(s1[0] == s3[0])dp[1][0] = true;
            if(s2[0] == s3[0])dp[0][1] = true;
        }
        else return false;// len3 = 0,但是len1和len2不等于0
        if(len1 + len2 != len3)return false;//长度关系不满足
        for(int i = 0; i <= len1; i++)
            for(int j = 0; j <= len2; j++)
            {
                int tmp = i+j-1;
                if(j > 0)
                {
                    if(dp[i][j-1] && s3[tmp] == s2[j-1])
                        {dp[i][j] = true; continue;}
                }
                if(i > 0)
                {
                    if(dp[i-1][j] && s3[tmp] == s1[i-1]) 
                        dp[i][j] = true;
                }
            }
        if(dp[len1][len2])return true;
        else return false;
    }
};
//二刷，4ms,56.45%
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if(len1+len2!=len3) return false;
        bool dp[len1+1][len2+1];
        memset(dp,false,sizeof(bool)*(len1+1)*(len2+1));
        dp[0][0] = true;
        for(int i=1;i<=len1;i++){
            if(s1[i-1] == s3[i-1]){
                dp[i][0] = true;
            }else{break;}
        }
        for(int i=1;i<=len2;i++){
            if(s2[i-1]==s3[i-1]){
                dp[0][i] = true;
            }else{break;}
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                int k=i+j;
                if(s1[i-1]==s3[k-1]) dp[i][j] = dp[i-1][j] || dp[i][j];
                if(s2[j-1]==s3[k-1]) dp[i][j] = dp[i][j-1] || dp[i][j];
            }
        }
        return dp[len1][len2];
    }
};