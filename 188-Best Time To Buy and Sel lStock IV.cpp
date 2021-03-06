/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
/*
采用动态规划来解决问题。 
我们需要维护如下两个量： 
global[i][j]:当前到达第i天最多可以进行j次交易，所得到的最大利润。 
local[i][j]:当前到达第i天最多可以进行j次交易，而且最后一次交易在当天卖出，所得到的最大利润。 
状态转移方程： 
global[i][j] = max(local[i][j], global[i-1][j]) 
上述方程比较两个量的大小：①当前局部最大值；②过往全局最大值。 
local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff) 
上述方程比较两个量的大小： 
①全局到i-1天进行j-1次交易，然后加上今天的交易（如果今天的交易赚钱的话）。 
②取局部第i-1天进行j次交易，然后加上今天的差值（local[i-1][j]是第i-1天卖出的交易，它加上diff后变成第i天卖出，并不会增加交易次数。无论diff是正还是负都要加上，否则就不满足local[i][j]必须在最后一天卖出的条件了）

另外需要注意的一个问题是，当k远大于数组的大小时，上述算法将变得低效。因此将其改用不限交易次数的方式解决。
*/
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) return 0;
        if (k >= prices.size()) return solveMaxProfit(prices);
        int g[k + 1] = {0};
        int l[k + 1] = {0};
        for (int i = 0; i < prices.size() - 1; ++i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; --j) {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
    int solveMaxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};
//8ms
/*
/**
 * dp[i, j] represents the max profit up until prices[j] using at most i transactions. 
 * dp[i, j] = max(dp[i, j-1], prices[j] - prices[jj] + dp[i-1, jj]) { jj in range of [0, j-1] }
 *          = max(dp[i, j-1], prices[j] + max(dp[i-1, jj] - prices[jj]))
 * dp[0, j] = 0; 0 transactions makes 0 profit
 * dp[i, 0] = 0; if there is only one price data point you can't make any transaction.
 */

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
            int n = prices.size();
            if (n <= 1)
                return 0;
            if (k >=  n/2) {
                int maxPro = 0;
                for (int i = 1; i < n; i++) {
                    if (prices[i] > prices[i-1])
                        maxPro += prices[i] - prices[i-1];
                }
                return maxPro;
            }
            int dp[k+1][n];
            memset(dp,0,sizeof(int)*(k+1)*n);
            for (int i=1;i<=k;i++) {
                int localMax = -prices[0];
                for (int j = 1; j < n; j++) {
                    localMax = max(localMax, dp[i-1][j] - prices[j]);
                    dp[i][j] = max(dp[i][j-1],  prices[j] + localMax);
                }
            }
            return dp[k][n-1];
        }
};