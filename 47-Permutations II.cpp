/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
//参考博客：http://www.cnblogs.com/TenosDoIt/p/3662644.html
//leetcode的全排列问题：http://www.cnblogs.com/felixfang/p/3705754.html
//                      http://www.cnblogs.com/felixfang/p/4064374.html

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        if(num.size() == 0)return res;
        vector<int> tmpres;
        permuteRecur(num, 0, res, tmpres);
        return res;
    }
     
    void permuteRecur(vector<int> &num, int index, vector<vector<int> >&res, vector<int>&tmpres)
    {
        if(index == num.size())
        {
            res.push_back(tmpres);
            return;
        }
        for(int i = index; i < num.size(); i++)
            if(i == index || !find(num, index, i, num[i]))
            {
                swap(num[index], num[i]);
                tmpres.push_back(num[index]);
                permuteRecur(num, index+1, res, tmpres);
                tmpres.pop_back();
                swap(num[index], num[i]);
            }
    }
    //从数组的[start,end）范围内寻找元素target
    bool find(vector<int> &num, int start, int end, int target)
    {
        for(int i = start; i < end; i++)
            if(num[i] == target)
                return true;
        return false;
    }
};
//
class Solution {
public:
    vector<vector<int>>  res;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        perm (nums,0);
        return res;
    }
    void perm(vector<int>& nums,int i){
        int N = nums.size();
        if(i == N) res.push_back(nums);
        set<int> s;
        for(int j=i;j<N;j++){
            //这里其实不是特别难理解，这样想：避免两个相同的元素交换位置
            if(s.find(nums[j]) != s.end()) continue;
            s.insert(nums[j]);
            swap(nums,i,j);
            perm(nums,i+1);
            swap(nums,i,j);
        }
    }
    void swap(vector<int>& nums,int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};