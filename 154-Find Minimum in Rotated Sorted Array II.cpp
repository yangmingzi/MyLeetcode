class Solution {
public:
    int findMinHelper(vector<int> &num, int left, int right) {
        int mid = (left + right) / 2;
        if (mid == left || mid == right) {
            return min(num[left], num[right]);
        }
        if (num[mid] < num[right]) {
            return findMinHelper(num, left, mid);
        } else if (num[mid] > num[right]) {
            return findMinHelper(num, mid, right);
        } else {
            //遇到重复元素，此步相当于去掉了一个，不影响寻找最小值
            return findMinHelper(num, left, right - 1);
        }
    }
    int findMin(vector<int> &num) {
       return findMinHelper(num, 0, num.size() - 1);
    }
};