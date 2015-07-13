/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/
/*
和上一题差不多，只是每个元素只能选一次。

由于有重复元素的存在，比如数组为[1(1),1(2),2,3]，target = 6. 可能出现重复结果1(1),2,3 和 1(2),2,3   

我们可以如下处理：如果数组中当前的数字出现重复，在前面重复了k次，且临时结果数组中也包含了k个当前数字，那么当前的数字可以选择；否则就不选择当前数字
*/

class Solution {
private:
    vector<vector<int> >res;
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmpres;
        helper(candidates, 0, target, tmpres, 0);
        return res;
    }
     
    //从数组candidates[index,...]寻找和为target的组合,times为前一个数字candidates[index-1]重复出现的次数
    void helper(vector<int> &candidates, const int index, const int target, vector<int>&tmpres, int times)
    {
        if(target == 0)
        {
            res.push_back(tmpres);
            return;
        }
        for(int i = index; i < candidates.size() && target >= candidates[i]; i++)
        {
            if(i > 0 && candidates[i] == candidates[i-1])times++;
            else times = 1;
            if(times == 1 || (tmpres.size() >= times-1 && tmpres[tmpres.size()-times+1] == candidates[i]))
            {
                tmpres.push_back(candidates[i]);
                helper(candidates, i+1, target - candidates[i], tmpres, times);
                tmpres.pop_back();
            }
        }
    }
};