/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/
/*
在前面解决过2*n+1的问题，现在面临的是2*n+2 的问题，
我们想用什么方法可以将2*n+2的问题划分为两个集合转化为2*n+1，然后在各个集合采用异或操作，最后可得到两个值。 
如何才能转化为2*n+1，只要解决这个，那么所有问题迎刃而解。 
解决关键：
所有数异或，得到最后结果，然后找最后一个非零位置。
根据这个位置做分类，所有这个位置为零的为一组，所有这个位置为一的为一组。 
找最后一个是1的位置，用算法： 
C-(C-1)&C 得到最后一个非零位置组成的数 
如C = 1100, 算出来的结果是0100.
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ret=0;
        for(int i=0;i<nums.size();i++){
            ret = ret ^ nums[i];
        }
        //int lastOneVal = ret - (ret & (ret - 1));
        int lastOneVal  = ret & (-ret);
        vector<int> vec1;
        vector<int> vec2;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & lastOneVal){
                vec1.push_back(nums[i]);
            }else{
                vec2.push_back(nums[i]);
            }
        }
        int ret1 = 0;
        int ret2 = 0;
        for(int i=0;i<vec1.size();i++){ret1^=vec1[i];}
        for(int i=0;i<vec2.size();i++){ret2^=vec2[i];}
        vector<int> res;
        res.push_back(ret1);
        res.push_back(ret2);
        return res;
    }
};