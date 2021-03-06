/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
/*
int 数据共有32位，可以用32变量存储 这 N 个元素中各个二进制位上 1  出现的次数，
最后 在进行 模三 操作，如果为1，那说明这一位是要找元素二进制表示中为 1 的那一位。代码如下：
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int bitnum[32] = {0};
        int res = 0;
        for(int i=0;i<32;i++){
            for(int j=0;j<n;j++){
                bitnum[i]+=(nums[j]>>i)&1;
            }
            res |= (bitnum[i]%3)<<i;
        }
        return res;
    }
};
/*
对于除出现一次之外的所有的整数，其二进制表示中每一位1出现的次数是3的整数倍，将所有这些1清零，剩下的就是最终的数。
用ones记录到当前计算的变量为止，二进制1出现“1次”（mod 3 之后的 1）的数位。用twos记录到当前计算的变量为止，二进制1出现“2次”（mod 3 之后的 2）的数位。当ones和twos中的某一位同时为1时表示二进制1出现3次，此时需要清零。即用二进制模拟三进制计算。最终ones记录的是最终结果。
博客：http://www.cnblogs.com/daijinqiao/p/3352893.html
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ones=0,twos=0,threes=0;
        for(int i=0;i<n;++i){
            twos |=(ones&nums[i]);
            ones ^= nums[i];
            threes = ~(ones&twos);
            ones &= threes;
            twos &= threes;
        }
        return ones;
    }
};