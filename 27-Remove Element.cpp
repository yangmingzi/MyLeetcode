/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
/*题目的意思是把数组中和给定的目标数字不同的元素，全部放到数组的前部
把不等于目标数字的元素依次放到首部，如果不等于目标数字的元素较少，这种方法效率更高*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int k = 0;
        for(int i = 0; i < n; i++)
            if(nums[i] != val)nums[k++] = nums[i];
        return k;
    }
};


//遍历数组，如果在当前位置 i 碰到元素等于给定的目标数字，从数组尾部找一个不等于目标的数字，放到 i 位置
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int n=nums.size();
        int k = n-1;
        for(int i = 0; i <= k; i++)
            if(nums[i] == val)
            {
                while(k > i && nums[k] == val)k--;//从后面找到第一个不是elem的元素
                if(k == i)return i;
                else nums[i] = nums[k--];//k位置非elem的元素放到i位置
            }
        return k+1;
    }
};
//其实遍历找到等于目标数字的元素后，只需要把数组尾部元素放到当前位置，不管尾部元素是否为目标数字   
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int n=nums.size();
        int k = n-1;
        for(int i = 0; i <= k;)
            if(nums[i] == val)
                nums[i] = nums[k--];//尾部元素放在当前位置
            else i++;
        return k+1;
    }
};