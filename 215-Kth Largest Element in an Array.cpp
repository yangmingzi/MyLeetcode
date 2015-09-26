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

/**/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> less;
        vector<int> large;
        int n = nums.size();
        int ta = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>ta) large.push_back(nums[i]);
            else if (nums[i]<ta) less.push_back(nums[i]);
        }
        if(large.size()>=k) return findKthLargest(large,k);
        if(n-less.size()<k) return findKthLargest(less,k-(n-less.size()));
        return ta;
     }
};
/*O(1)空间复杂度*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int L=0,R=nums.size()-1;
        while(L<R){
            int left = L ,right = R;
            int key  = nums[left];
            while(left<right){
                while(left<right && nums[right]<key) --right;
                nums[left] = nums[right];
                while(left<right && nums[left]>=key) ++left;
                nums[right] = nums[left];
            }
            nums[left] = key;
            if(left == k-1) return nums[k-1];
            else if(left > k-1) R= left - 1;
            else L = left + 1;
        }
        return nums[k-1];
    }
};

