/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/
//非边界部分线性扫描，边界部分特殊处理
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len=nums.size();
        for(int i=1;i<len-1;i++){
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
               return i;
        }
        if(nums[0]>nums[1]) return 0;
        if(nums[len-1]>nums[len-2]) return len-1;
    }
};

//二分查找
class Solution {
public:
   int findPeakElement(const vector<int> &num) {
        int left=0,right=num.size()-1;
        while(left<=right){
            if(left==right)
                return left;
            int mid=(left+right)/2;
            if(num[mid]<num[mid+1])
                left=mid+1;
            else
                right=mid;
        }
    }
};