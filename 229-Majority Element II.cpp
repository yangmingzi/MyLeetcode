/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. 
The algorithm should run in linear time and in O(1) space.
*/
/*
摩尔投票法。
投票法的核心是找出两个候选众数进行投票，需要两遍遍历，
第一遍历找出两个候选众数，
第二遍遍历重新投票验证这两个候选众数是否为众数即可。
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int m = 0, n = 0, cm = 0, cn = 0;
        //for循环地下的if逻辑顺序不可以变，否则会出现【7,7,8,8,8】但返回【8】
        //因为如果先判断计数器，会导致在一开始m和n同时等于7
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == m)
            {
                cm++;
            }
            else if (nums[i] == n)
            {
                cn++;
            }
            else if (cm == 0)
            {
                m = nums[i];
                cm = 1;
            }
            else if (cn == 0)
            {
                n = nums[i];
                cn = 1;
            }
            else
            {
                --cm;
                --cn;
            }
        }

        cm = cn = 0;
        for (auto& a : nums)
        {
            if (a == m)
            {
                cm++;
            }
            else if (a== n)
            {
                cn++;
            }
        }
        if (cm > nums.size() / 3)
        {
            res.push_back(m);
        }
        if (cn > nums.size() / 3)
        {
            res.push_back(n);
        }

        return res;
    }
};