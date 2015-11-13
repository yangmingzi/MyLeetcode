/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/
//自己做的
class NumArray {
public:
    vector<int> sumQ;
    int len;
    NumArray(vector<int> &nums) {
        if(nums.size() == 0) return;
        sumQ = nums;
        len = nums.size();
        sumQ[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            sumQ[i] = nums[i]+sumQ[i-1];
        }
    }

    int sumRange(int i, int j) {
        if(i>=0 && j<len){
            if(i>0){
                return sumQ[j]-sumQ[i-1];
            }else{
                return sumQ[j];
            }
        }
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);