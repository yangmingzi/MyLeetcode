/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
/*
分析：顺序查找肯定是可以的，可不可以找出效率更高的查找算法？其实二分查找也可以用在这里。那么和普通的二分查找有什么区别呢？

当target < A[middle]时，普通二分查找是让查找区间右边界iend = middle - 1，
这一题中不能直接这么操作，因为我们查找的元素有可能在middle的后半段，
例如在5 6 7 8 9 1 2 3中查找2，中间元素时8, 虽然2 < 8, 
但是我们还是要在middle后半段查找，那么什么时候会出现这种情况呢，要满足三个条件：
a、查找区间的尾部元素小于首部元素，这表示查找区间不是全部有序的，

b、target不大于查找区间的尾部元素，这表示target在旋转前数组的前半部分，

c、中间元素要大于查找区间尾部元素，这表示中间元素在旋转前数组的后半部分。

如果没有同时满足这三个条件那么我们要去middle的前半段查找。

当target > A[middle]时，普通二分查找要到middle后半段查找，
这一题中比如 在7 8 9 1 2 3 5 6中查找8, 中间元素时1，8 > 1但是还是需要到前半段查找。
到前半段查找时，也需要同时满足三个条件：
a、查找区间的尾部元素小于首部元素，这表示查找区间不是全部有序的 

b、target大于查找区间的尾部元素，这表示target在旋转前数组的后半部分

c、中间元素要小于查找区间尾部元素，这表示中间元素在旋转前数组的前半部分。

   如果没有同时满足这三个条件那么我们要去middle的后半段查找。

当target = A[middle]时 直接返回查找结果
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int istart = 0, iend = n-1, mid;
        while(istart <= iend)
        {
            mid = (istart + iend) / 2;
            if(nums[mid] > target)
            {
                if(nums[iend] < nums[istart] && target <= nums[iend] && nums[mid] > nums[iend])
                            istart = mid + 1;
                else iend = mid - 1;
            }
            else if(nums[mid] < target)
            {
                if(nums[iend] < nums[istart] && target > nums[iend] && nums[mid] < nums[iend])
                            iend = mid - 1;
                else istart = mid + 1;
            }
            else return mid;
        }
        return -1;
    }
};