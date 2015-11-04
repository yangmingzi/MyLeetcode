/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
//http://blog.csdn.net/hcbbt/article/details/43975275
//分治，48ms,24.05%
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int m=nums1.size();
        int n=nums2.size();
        vector<int>  tmp;
        while(i<m || j<n){
            if(i == m){
                tmp.push_back(nums2[j++]);
            }
            else if(j == n){
                tmp.push_back(nums1[i++]);
            }
            else if(nums1[i]<nums2[j]){
                tmp.push_back(nums1[i++]);
            }else{
                tmp.push_back(nums2[j++]);
            }
        }
        if((m+n)%2 == 0) return (tmp[(m+n)/2-1]+tmp[(m+n)/2])/2.0;
        else return tmp[(m+n)/2];
    }
};