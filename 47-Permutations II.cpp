/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
//参考博客：http://www.cnblogs.com/TenosDoIt/p/3662644.html
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