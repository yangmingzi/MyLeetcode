//三种解法，第三种解法太牛逼了
//参考博客：http://blog.csdn.net/foreverling/article/details/43925891
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
        }
        k = k % n;
        for (int i = 0; i < n; i++)
        {
            nums[i] = temp[(i - k + n) % n];
        }
      
    }
};