/*
Given a sorted array and a target value, return the index if the target is found.
 If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
/*
这就是普通的二分查找,需要注意的地方代码注释中都有。
其中特别注意的是：
middle=（low+high）/ 2 ，可能会溢出，可以替换为middle = low + ((high - low)>>2);

根据程序员编程艺术第二十五章：Jon Bentley：90%无法正确实现二分查找, 
如果high初始化为n, 那么while判断语句就应该是low<high, 
下面的A[middle] > target分支中,就应该是high = middle
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //二分查找
        int n=nums.size();
        int low = 0, high = n-1;//注意这里high是初始化为n-1
        while(low <= high)//注意这里是<=号
        {
            //int middle = (low + high) / 2;
            int middle = low + ((high - low)>>2); //可以防止low + high 溢出
            if(nums[middle] < target)
                low = middle + 1;
            else if(nums[middle] > target)
                high = middle - 1;
            else return middle;
        }
        return low;//注意返回值是low
    }
};