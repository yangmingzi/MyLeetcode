/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
//这篇博客用了4种方法：http://blog.csdn.net/tuantuanls/article/details/8717262
/*
类似于DFS的递归. 
对于包含n个元素的数组,先确定第一位置的元素，第一个位置有n中可能(每次把后面的元素和第一个元素交换)，
然后求子数组[2…n]的全排列。由于一个数列的总共有n！个排列，因此时间复杂度为O（n！）
*/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
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
            {
                swap(num[index], num[i]);
                tmpres.push_back(num[index]);
                permuteRecur(num, index+1, res, tmpres);
                tmpres.pop_back();
                swap(num[index], num[i]);
            }
    }
};

//
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
       perm(nums,0);
       return res;
    }
    void perm(vector<int> &nums,int i){
        int N = nums.size();
        if(i == N) res.push_back(nums);
        for(int j=i;j<N;j++){
            swap(nums,i,j);
            perm(nums,i+1);
            swap(nums,i,j);
        }
        
    }
    void swap(vector<int> &nums,int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};