/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Subscribe to see which companies asked this question
*/
/*
这道是买股票的最佳时间系列问题中最难最复杂的一道，前面两道Best Time to Buy and Sell Stock 买卖股票的最佳时间和Best Time to Buy and Sell Stock II 买股票的最佳时间之二的思路都非常的简洁明了，算法也很简单。而这道是要求最多交易两次，找到最大利润，还是需要用动态规划Dynamic Programming来解，而这里我们需要两个递推公式来分别更新两个变量local和global，参见网友Code Ganker的博客，我们其实可以求至少k次交易的最大利润，找到通解后可以设定 k = 2，即为本题的解答。我们定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。它们的递推式为：

local[i][j]=max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff)

global[i][j]=max(local[i][j],global[i-1][j])，

其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值中取较大值，而全局最优比较局部最优和前一天的全局最优。
*/
//1刷，12ms,10.77
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int g[3] = {0};
        int l[3] = {0};
        for (int i = 0; i < prices.size() - 1; ++i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = 2; j >= 1; --j) {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(l[j], g[j]);
            }
        }
        return g[2];
    }
};
//二刷，8ms,81.1%
/*
题意：用一个数组表示股票每天的价格，数组的第i个数表示股票在第i天的价格。最多交易两次，手上最多只能持有一支股票，求最大收益。

分析：动态规划法。以第i天为分界线，计算第i天之前进行一次交易的最大收益preProfit[i]，和第i天之后进行一次交易的最大收益postProfit[i]，最后遍历一遍，max{preProfit[i] + postProfit[i]} (0≤i≤n-1)就是最大收益。第i天之前和第i天之后进行一次的最大收益求法同Best Time to Buy and Sell Stock I。

代码：时间O(n)，空间O(n)。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int n = prices.size();
        int prePro[n];
        memset(prePro,0,sizeof(int)*n);
        int postPro[n];
        memset(postPro,0,sizeof(int)*n);
        int curMin = prices[0];
        int curMax = prices[n-1];
        for(int i=1;i<n;i++){
            curMin    = min(curMin,prices[i]);
            prePro[i] = max(prePro[i-1],prices[i]-curMin);
        }
        for(int i = n-2;i>=0;i--){
            curMax     = max(curMax,prices[i]);
            postPro[i] = max(postPro[i+1],curMax-prices[i]);
        }
        int maxPro = 0;
        for(int i=0;i<n;i++){
            int tmp = prePro[i]+postPro[i];
            maxPro = max(maxPro,tmp);
        }
        return maxPro;
    }
};