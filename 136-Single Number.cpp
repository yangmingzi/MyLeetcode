/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
/*
初始化一个int num=0，然后用这个num和数组里的每个数都异或一遍，
因为两个相同的数异或后会变成0，
所以遍历到最后是0和那个单独的数异或，结果即为那个单独的数，
注意到，0和0异或还是0，所以要初始化为0.
异或运算
1. a ^ a = 0
2. a ^ b = b ^ a
3. a ^ b ^ c = a ^ (b ^ c) = (a ^ b) ^ c
4. d = a ^ b ^ c 可以推出 a = d ^ b ^ c
5. a ^ b ^ a = b
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]^nums[i-1];
        }
        return nums[nums.size()-1];
    }
};
//
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ret=0;
        for(int i=0;i<nums.size();i++){
            ret ^= nums[i];
        }
        return ret;
    }
};