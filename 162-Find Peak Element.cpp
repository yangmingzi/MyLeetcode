//非边界部分线性扫描，边界部分特殊处理
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len=nums.size();
        for(int i=1;i<len-1;i++){
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
               return i;
        }
        if(nums[0]>nums[1]) return 0;
        if(nums[len-1]>nums[len-2]) return len-1;
    }
};
