/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/
//dp[i][j]=max(dp[i][k-1]+nums[i-1]*nums[k]*nums[j+1]+dp[k+1][j]) k∈[i,j]
 class Solution {
public:
    int maxCoins(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                --i;
            }
        }
        int n=nums.size();
        if(n==0) return 0;
        //if(n==1) return nums[0];
        //if(n==2) return nums[0]*nums[1]+max(nums[0],nums[1]);
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        int m=nums.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        for(int count=1;count<=n;++count){
            for(int start=1;start+count-1<=n;++start){
                int bestcoins=0;
                for(int b=0;b<count;++b){
                    bestcoins=max(bestcoins,dp[start][start+b-1]+nums[start-1]*nums[start+b]*nums[start+count]+dp[start+b+1][start+count-1]);

                }
                dp[start][start+count-1]=bestcoins;
            }

        }
        return dp[1][n];
    }
};