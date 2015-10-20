/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/
//滑动窗口
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, len = nums.size(), start = 0;
        bool flag = false;
        for (int end = 0; end < nums.size(); ++end) {
            sum += nums[end];
            while (sum >= s) {
                flag = true;
                len = min(len, end - start + 1);
                //通过前向缩进减小窗口长度，检查此时sum是否满足，不满足则后向扩张
                //如何证明没有遗漏？
                sum -= nums[start];
                start++;
            }
        }
        return flag ? len : 0;
    }
};

//二刷 一刷 速度相同  4ms  29.31%
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0) return 0;
        int res= INT_MAX ;
        int i=0,j=0,sum=0;
        while(i<=j && j<nums.size() && sum<s){
            sum+=nums[j];
            while(i<=j && sum>=s){
                res = min(res,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return res==INT_MAX?0:res;
    }
};