//经典题目，参考博客：http://www.cnblogs.com/TenosDoIt/p/3465240.html
class Solution {
public:
    bool search(vector<int> nums, int target) {
    int n=nums.size();
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l)/2;
        if (nums[m] == target) return true; //return m in Search in Rotated Array I
        if (nums[l] < nums[m]) { //left half is sorted
            if (nums[l] <= target && target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        } else if (nums[l] > nums[m]) { //right half is sorted
            if (nums[m] < target && target <= nums[r])
                l = m + 1;
            else
                r = m - 1;
        } else l++;
    }
    return false;
    }
};