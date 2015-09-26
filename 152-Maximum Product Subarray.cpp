/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/
/*
这道题跟Maximum Subarray模型上和思路上都比较类似，还是用一维动态规划中的“局部最优和全局最优法”。
这里的区别是维护一个局部最优不足以求得后面的全局最优，这是由于乘法的性质不像加法那样，累加结果只要是正的一定是递增，
乘法中有可能现在看起来小的一个负数，后面跟另一个负数相乘就会得到最大的乘积。不过事实上也没有麻烦很多，
我们只需要在维护一个局部最大的同时，在维护一个局部最小，
这样如果下一个元素遇到负数时，就有可能与这个最小相乘得到当前最大的乘积和，这也是利用乘法的性质得到的。
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int n=nums.size();
        int tmp_max=nums[0],tmp_min=nums[0];
        for(int i=1;i<n;i++){
            int cpy_max=tmp_max;
            tmp_max=max(max(tmp_max*nums[i],nums[i]),tmp_min*nums[i]);
            tmp_min=min(min(cpy_max*nums[i],nums[i]),tmp_min*nums[i]);
            res=max(res,tmp_max);
        }
        return res;
    }
};

/**/

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n<=0) return 0;
        if(n==1) return nums[0];
        int max_local = nums[0];
        int min_local = nums[0];
        int global = nums[0];
        for(int i=1;i!=n;++i){
            int min_copy = min_local;
            min_local = MIN(MIN(nums[i]*max_local ,nums[i]),nums[i]*min_local);
            max_local = MAX(MAX(nums[i]*max_local,nums[i]),nums[i]*min_copy);
            global = MAX(global,max_local);
        }
        return global;
    }
};