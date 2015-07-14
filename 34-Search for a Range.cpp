/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
/*
看到这个有没有想到STL中的equal_range函数,这个函数是调用lower_bound和upper_bound, 下面我们仿照STL的实现。
相比上一题的二分查找，lower_bound当A[middle] == target时，继续向左半部分查找，
它返回的是第一个不小于目标数的元素位置；upper_bound当A[middle] == target时，
继续向右半部分查找，它返回的是第一个大于目标数的元素位置。
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums,  int target) {
        int n=nums.size();
        vector<int> res(2, -1);
        int low = 0, high = n-1;
        while(low <= high)
        {
            int middle = low + ((high - low)>>2);
            if(nums[middle] < target)
                low = middle + 1;
            else if(nums[middle] > target)
                high = middle - 1;
            else
            {
                res[0] = lowerBound(nums, low, middle - 1, target);
                res[1] = upperBound(nums, middle + 1, high, target) - 1;
                return res;
            }
        }
        return res;
    }
     
    //找到范围内[left,right]内第一个不小于target的元素
    int lowerBound(vector<int>& nums, int left, int right, int target)
    {
        int low = left, high = right;
        while(low <= high)
        {
            int middle = low + ((high - low)>>2);
            if(nums[middle] < target)
                low = middle + 1;
            else high = middle - 1;
        }
        return high + 1;//注意这里返回值不是low
    }
    //找到范围[left,right]内第一个大于target的元素
    int upperBound(vector<int>& nums, int left, int right, int target)
    {
        int low = left, high = right;
        while(low <= high)
        {
            int middle = low + ((high - low)>>2);
            if(nums[middle] <= target)
                low = middle + 1;
            else high = middle - 1;
        }
        return low;
    }
};