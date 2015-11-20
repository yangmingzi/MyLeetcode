/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/
public class NumArray {
    vector<int> arr;
    vector<int> tree;
    int length;
    public NumArray(vector<int>& nums) {
        length = nums.length;
        arr = nums;
        tree = nums;
        nums.push_back(0);
        for (int i = 0; i < length; i++) {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int delta = val - arr[i];
        arr[i] = val;
        i++;
        while(i <= length) {
            tree[i] += delta;
            i += i&(-i);
        }
    }

    public int sumRange(int i, int j) {
        int sumi = 0;
        int sumj = 0;
        j++;
        while (i > 0) {
            sumi += tree[i];
            i -= i &(-i);
            sumj += tree[j];
            j -= j &(-j);
        }
        while (j > 0) {
            sumj += tree[j];
            j -= j &(-j);
        }
        return sumj - sumi;
    }
}