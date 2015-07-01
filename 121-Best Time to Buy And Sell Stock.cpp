//动态规划
//假设交易市场共开放n天，第i天买入，则最大利润应该是[i+1,n]中的max时出手
//最关键的是：倒着查找。
//因为最晚也要在最后一天卖出！！！这样遍历可以记录每一天的利润进行比较而且不会产生逻辑混乱的错误。
//maxPrice = max(price[i],maxPrice)
//ans = max(ans,maxPrice-price[i])
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0)
            return 0;
            
        int maxPrice = prices[prices.size()-1];
        int ans = 0;
        for(int i = prices.size() - 1; i >= 0; i--)
        {
            maxPrice = max(maxPrice, prices[i]);
            ans = max(ans, maxPrice - prices[i]);
        }
        
        return ans;
    }
};