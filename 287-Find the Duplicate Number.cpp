/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/
//http://segmentfault.com/a/1190000003817671
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int high = n-1;
        int low  = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            int count = 0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid){
                    count++;
                }
            }
            if(count>mid) high = mid - 1;
            if(count<=mid) low  = mid + 1;
        }
        return low;
    }
};