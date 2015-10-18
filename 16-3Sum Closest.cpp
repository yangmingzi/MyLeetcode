/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
/*
我们可以在 2sum问题 的基础上来解决3sum问题，假设3sum问题的目标是target。
每次从数组中选出一个数k，从剩下的数中求目标等于target-k的2sum问题。
这里需要注意的是有个小的trick：当我们从数组中选出第i数时，我们只需要求数值中从第i+1个到最后一个范围内字数组的2sum问题。
我们以选第一个和第二个举例，假设数组为A[],总共有n个元素A1，A2....An。
很显然，当选出A1时，我们在子数组[A2~An]中求目标位target-A1的2sum问题，
我们要证明的是当选出A2时，我们只需要在子数组[A3~An]中计算目标位target-A2的2sum问题，而不是在子数组[A1,A3~An]中，证明如下：
假设在子数组[A1,A3~An]目标位target-A2的2sum问题中，存在A1 + m = target-A2（m为A3~An中的某个数），即A2 + m = target-A1，
这刚好是“对于子数组[A3~An],目标位target-A1的2sum问题”的一个解。即我们相当于对满足3sum的三个数A1+A2+m = target重复计算了。
因此为了避免重复计算，在子数组[A1，A3~An]中，可以把A1去掉，再来计算目标是target-A2的2sum问题。

对于本题要求的求最接近解，只需要保存当前解以及当前解和目标的距离，如果新的解更接近，则更新解。算法复杂度为O（n^2）;
注意：我们这里是求的和是一个非确定性的数，因此2sum问题的hashtable解法就不适合这里了
*/
//12ms
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        sort(num.begin(), num.end());
        int res, dis = INT_MAX;
        for(int i = 0; i < n - 2; i++)
        {
            int target2 = target - num[i], tmpdis;
            int tmpres = twoSumClosest(num, i+1, target2);
            if((tmpdis = abs(tmpres - target2)) < dis)
            {
                res = tmpres + num[i];
                dis = tmpdis;
                if(res == target)
                    return res;
            }
        }
        return res;
    }
    
    int twoSumClosest(vector<int> &sortedNum, int start, int target)
    {
        int head = start, tail = sortedNum.size() - 1;
        int res, dis = INT_MAX;
        while(head < tail)
        {
            int tmp = sortedNum[head] + sortedNum[tail];
            if(tmp < target)
            {
                if(target - tmp < dis)
                {
                    res = tmp;
                    dis = target - tmp;
                }
                head++;
            }
            else if(tmp > target)
            {
                if(tmp - target < dis)
                {
                    res = tmp;
                    dis = tmp - target;
                }
                tail--;
            }
            else
                return target;
        }
        return res;
    }
};


//16ms

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX;
        int ret;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int j=i+1;
            int k= n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                int tmp = abs(sum-target);
                if(res>tmp){res=tmp;ret = sum;}
                if(sum==target){return sum;}
                else if(sum<target){
                    j++;
                    while(j<k && nums[j] == nums[j-1]){j++;}
                }
                else{
                    k--;
                    while(j<k && nums[k] == nums[k+1]){k--;}
                }
            }
        }
        return ret;
       
    }
};