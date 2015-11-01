/*
Given an array of n integers where n > 1, nums, 
return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? 
(Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/
/*
res[i] = nums[0]*....nums[i-1]*nums[i+1]*....nums[n-1]
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            res[i]=res[i-1]*nums[i-1];
        }
        int right = 1;
        for(int i=nums.size()-1;i>=0;i--){
            res[i]  = right*res[i];
            right  *= nums[i];
        }
        return res;
    }
};
//
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        int left = 1;
        int right = 1;
        for(int i=1;i<n;i++){
            left = left * nums[i-1];
            res[i] = left ;
        }
        for(int j=n-2;j>=0;j--){
            right = right * nums[j+1];
            if(j == 0) {res[j] = right;}
            else res[j] = res[j]*right;
        }
        return res;
        // int n = nums.size();
        // if(n==0) return {0};
        // if(n==1) return {0};
        // int dp[n][n];
        // vector<int> res;
        // memset(dp,0,sizeof(int)*n*n);
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(i == j){ dp[i][j] = nums[i];}
        //         else{
        //             dp[i][j] = dp[i][j-1]*nums[j];
        //         }
        //     }
        // }
        // res.push_back(dp[1][n-1]);
        // if(n>2){
        //     for(int i=1;i<n-1;i++){
        //         res.push_back(dp[0][i-1]*dp[i+1][n-1]);
        //     }
        // }
        // res.push_back(dp[0][n-2]);
        // return res;
    }
};