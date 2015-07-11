class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //只要当前元素和前一个的前一个不同就保留
        int n=nums.size();
        if(n == 0) {return 0;}
        if(n <= 2)return n;
        int index = 2;
        int lastChange, lastChangeIndex = -1; //上一次被覆盖的位置和被覆盖的值
        for(int i = 2; i < n; i++)
        {
            int prepre = nums[i-2];
            if(i-2 == lastChangeIndex)prepre = lastChange;//原来的A[i-2]有可能被覆盖了
            if(nums[i] != prepre)
            {
                lastChangeIndex = index;
                lastChange = nums[index];
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};