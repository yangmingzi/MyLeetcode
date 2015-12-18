/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/
/*
Generally this problem cannot be directly solved by greedy algorithm 
because the total value of the strategy you make on day 'i' will have an influence on the future because of the cool down, 
and that means a locally optimal plan is not necessarily a globally optimal plan.

To be greedy, we need to divide the problem into 2 sets and maybe on each set we can implement the greedy algorithm! 
Because we don't want the current operation to influence the future
(which will result in a situation where a globally optimal plans don't include a locally optimal optimal plan). 
The influence to future is dependent on whether you have the stock at the beginning of day i. 
Thus you use two variables to represent the best profit on day i. 
Variable 'have' means you have the stock at the beginning of day i.
Variable 'non' you don't have it at the beginning of that day.
So in this way, variable 'have' will always take the risk of price change , but 'non' won't. 
so the price part is fixed, we need to be greedy on past. 
The greedy choice for 'have' on day i is the larger one of the 2 variables: 'have' on day i-1 or 'non' on day i-2. 
And the greedy choice for 'non' on day i is the larger one of 'have' on day i-1 or 'non' on day i-1. 
And the best plan is the larger one of the two variables on day n.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int i,j,c=prices.size();
        int have=prices[1]-prices[0],non=0,nonn=0,temp;
        for(i=2;i<c;i++){
            temp=have;
            have=max(have,nonn)+prices[i]-prices[i-1];
            nonn=non;
            non=max(temp,non);
        }
        return max(have,non);

    }
};