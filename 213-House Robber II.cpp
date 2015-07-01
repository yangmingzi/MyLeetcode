//动态规划
//两种可能（偷不偷第一家或者说偷不偷最后一家），两种约束
class Solution {
public:
    int rob(vector<int>& nums) {
        int N=nums.size();
        int dp[N],dr[N];
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<N;i++){
        	dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        dr[N-1] = nums[N-1];
        dr[N-2] = max(nums[N-1],nums[N-2]);
        for(int i=N-3;i>=1;i--){
        	dr[i]=max(dr[i+1],dr[i+2]+nums[i]);
        }
        return  max(dr[1],dp[N-2]);//dp[N-2]:不偷最后一家，第一家可偷。dr[1]不偷第一家，最后一家可偷。
    }
};