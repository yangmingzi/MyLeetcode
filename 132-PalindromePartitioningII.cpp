//动态规划，dp[i]表示从s_0到s_i的最小cut，
//为了避免重复比较，定义标记矩阵flag[i][j]，用来存储s_i到s_j是否为回文。
class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.length(), 0);
        vector<vector<bool> > flag(s.length(), vector<bool>(s.length(), false));
        flag[0][0] = true;
        for (int j = 1; j < s.length(); ++j) {
            flag[j][j] = true;
            dp[j] = dp[j-1] + 1;
            for (int i = 0; i < j; ++i) {
                if (s[i] == s[j] && (i == j - 1 || flag[i+1][j-1])) {
                    //如果从第一位开始回文，则无需切
                    //否则，比较从前面切和从上一处切那种方式切的次数更少
                    dp[j] = (i == 0) ? 0 : min(dp[j], dp[i-1] + 1);
                    flag[i][j] = true;//矩阵不是对称矩阵
                }
            }
        }
        return dp[s.length()-1];
    }
};

