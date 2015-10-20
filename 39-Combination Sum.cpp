/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/
/*
简单的回溯法(递归实现).

比如对于数组3,2,6,7,target = 7,对数组排序得到[2,3,6,7]

1、第1个数字选取2, 那么接下来就是解决从数组[2,3,6,7]选择数字且target = 7-2 = 5

2、第2个数字选择2，那么接下来就是解决从数组[2,3,6,7]选择数字且target = 5-2 = 3

3、第3个数字选择2，那么接下来就是解决从数组[2,3,6,7]选择数字且target = 3-2 = 1

4、此时target = 1小于数组中的所有数字，失败，回溯，重新选择第3个数字

5、第3个数字选择3，那么接下来就是解决从数组[2,3,6,7]选择数字且target = 3-3 = 0

6、target = 0，找到了一组解，继续回溯寻找其他解

需要注意的是：如果数组中包含重复元素，我们要忽略（因为每个数字可以选择多次，如果不忽略的话，就会产生重复的结果）。貌似oj的测试集数组中都不包含重复的数字
*/
//一刷，36ms , 21.67%
class Solution {
private:
    vector<vector<int> > res;
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());//为了输出结果递增，因此先对数组排序
        vector<int> tmpres;
        helper(candidates, 0, target, tmpres);
        return res;
    }
     
    //从数组candidates[index,...]寻找和为target的组合
    void helper(vector<int> &candidates, const int index, const int target, vector<int>&tmpres)
    {
        if(target == 0)
        {
            res.push_back(tmpres);
            return;
        }
        for(int i = index; i < candidates.size() && target >= candidates[i]; i++)
            if(i == 0 || candidates[i] != candidates[i-1])//由于每个数可以选取多次，因此数组中重复的数就不用考虑
            {
                tmpres.push_back(candidates[i]);
                helper(candidates, i, target - candidates[i], tmpres);
                tmpres.pop_back();
            }
    }
};

//二刷，16ms,66.2%
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0,tmp,0);
        return res;
    }
    void dfs(vector<int>& can,int target,int curSum,vector<int>& tmp,int dep){
        if(curSum == target){res.push_back(tmp);}
        for(int i = dep;i<can.size();i++){
            if(i ==0 || can[dep]!=can[dep-1]){
                if(curSum+can[i]<=target){
                    tmp.push_back(can[i]);
                    dfs(can,target,curSum+can[i],tmp,i);
                    tmp.pop_back();
                }
            }
        }
    }
};