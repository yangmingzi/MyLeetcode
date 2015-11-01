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
//二刷
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp1(n,0);
        vector<int> dp2(n,0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0],nums[1]);
        dp2[1] = nums[1];
        dp2[2] = max(nums[1],nums[2]);
        for(int i=2;i<n-1;i++){
            dp1[i] = max(dp1[i-2]+nums[i],dp1[i-1]);
        }
        for(int j=3;j<n;j++){
            dp2[j] = max(dp2[j-2]+nums[j],dp2[j-1]);
        }
        return max(dp1[n-2],dp2[n-1]);
    }
};