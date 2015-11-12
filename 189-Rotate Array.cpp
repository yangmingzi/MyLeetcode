/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/
//三种解法,参考博客：http://blog.csdn.net/foreverling/article/details/43925891
//24ms
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
        }
        k = k % n;
        for (int i = 0; i < n; i++)
        {
            nums[i] = temp[(i - k + n) % n];
        }
      
    }
};
//24ms
/*
①将整个数组反转 
②将由分割点分割的两个数组分别反转 
即：1 2 3 4 5 6 7 -> 7 6 5 | 4 3 2 1 -> 5 6 7 | 1 2 3 4 
时间复杂度为O(n)，空间复杂度为O(1)。
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        rev(nums, 0, n - 1);
        rev(nums, 0, k - 1);
        rev(nums, k, n - 1);
    }

    void rev(vector<int>& nums, int left, int right)
    {
        int temp;
        while (left < right)
        {
            temp = nums[left];
            nums[left++] = nums[right];
            nums[right--] = temp;
        }
    }
};