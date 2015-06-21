//动态规划
class Solution {
public:
    int rob(vector<int>& nums) {
        int N=nums.size();
        if(N==0) return 0;
        if(N==1) return nums[0];
        if(N==2) return max(nums[0],nums[1]);
       
        int dp[N];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<N;i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return max(dp[N-1],dp[N-2]);
    }
};