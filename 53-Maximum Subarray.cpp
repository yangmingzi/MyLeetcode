/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/
/*参考博客：http://www.cnblogs.com/springfor/p/3877058.html
http://www.cnblogs.com/TenosDoIt/p/3698246.html*/
/*
O(n)解法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //最大字段和问题
        int n = nums.size();
        int res = INT_MIN, sum = -1;
        for(int i = 0; i < n; i++)
        {
            if(sum > 0)
                sum += nums[i];
            else sum = nums[i];
            if(sum > res)res = sum;
        }
        return res;
    }
};
*/

//O(nlgn)解法，分治
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //最大字段和问题
        int n = nums.size();
        return helper(nums, 0, n-1);
    }
private:
    int helper(vector<int>& nums, const int istart, const int iend)
    {
        if(istart == iend)return nums[iend];
        int middle = (istart + iend) / 2;
        int maxLeft = helper(nums, istart, middle);
        int maxRight = helper(nums, middle + 1, iend);
        int midLeft = nums[middle];
        int tmp = midLeft;
        for(int i = middle - 1; i >= istart; i--)
        {
            tmp += nums[i];
            if(midLeft < tmp)midLeft = tmp;
        }
        int midRight = nums[middle + 1];
        tmp = midRight;
        for(int i = middle + 2; i <= iend; i++)
        {
            tmp += nums[i];
            if(midRight < tmp)midRight = tmp;
        }
        return max(max(maxLeft, maxRight), midLeft + midRight);
    }
};


