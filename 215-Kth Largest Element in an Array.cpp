//快速选择，快速排序算法的变形
//
class Solution {
public:
  int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int l = left + 1, r = right;
    while (l <= r) {
        if (nums[l] < pivot && nums[r] > pivot)//为什么不能把if写成while?
            swap(nums[l++], nums[r--]);
        if (nums[l] >= pivot) l++;
        if (nums[r] <= pivot) r--;
    }
    swap(nums[left], nums[r]);//为什么是r?
    return r;
}
int findKthLargest(vector<int>& nums, int k) {
    int left = 0, right = nums.size() - 1;
    while (true) {
        int pos = partition(nums, left, right);
        if (pos == k - 1) return nums[pos];
        if (pos < k - 1) left = pos + 1;
        else right = pos - 1;
    }
}
};

