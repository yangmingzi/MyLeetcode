/*
由于题目假设了A可以存放所有A和B的元素，因此我们可以从两个数组的尾部开始遍历，
将较大者放入数组A尾部（尾部下标递减）。时间复杂度O（m+n）,常数空间复杂度
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         //同时从两个数组尾部开始遍历，将较大者放在A的尾部
        int i = m+n-1, ia = m-1, ib = n-1;
        while(ia >= 0 && ib >= 0)
            nums1[i--] = nums1[ia] > nums2[ib] ? nums1[ia--] : nums2[ib--];
        while(ib >= 0)nums1[i--] = nums2[ib--];
    }
};