/*
Given a sorted array, 
remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, 
you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, 
with the first two elements of nums being 1 and 2 respectively. 
It doesn't matter what you leave beyond the new length.
*/
/*
从数组的第二个元素开始遍历，
把和上一个位置的值不同的的元素保存下来，
注意一下n == 0的情形（这里我们直接是inplace操作）
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums ) {
        int n=nums.size();
        if (n == 0) {return 0;}
        int index = 1;
        for(int i = 1; i < n; i++)
            if(nums[i] != nums[i-1])
                nums[index++] = nums[i];
        return index;
    }
};