//滑动窗口
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, len = nums.size(), start = 0;
        bool flag = false;
        for (int end = 0; end < nums.size(); ++end) {
            sum += nums[end];
            while (sum >= s) {
                flag = true;
                len = min(len, end - start + 1);
                //通过前向缩进减小窗口长度，检查此时sum是否满足，不满足则后向扩张
                //如何证明没有遗漏？
                sum -= nums[start];
                start++;
            }
        }
        return flag ? len : 0;
    }
};