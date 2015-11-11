/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
Subscribe to see which companies asked this question
*/
//8 ms，7.58%
class Solution {
private:
    vector<vector<int> >res;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //先排序，然后dfs每个元素选或者不选，最后叶子节点就是所有解
        res.clear();
        sort(S.begin(), S.end());
        vector<int>tmpres;
        dfs(S, 0, tmpres);
        return res;
    }
    void dfs(vector<int> &S, int iend, vector<int> &tmpres)
    {
        if(iend == S.size())
            {res.push_back(tmpres); return;}
        //选择S[iend]
        tmpres.push_back(S[iend]);
        dfs(S, iend+1, tmpres);
        tmpres.pop_back();
        //不选择S[iend]
        dfs(S, iend+1, tmpres);
    }
};
//二刷，，自己做，8 ms，7.58%
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int  n = nums.size();
        res.clear();
        vector<int> tmp;
        tmp.clear();
        res.push_back(tmp);
        if(n==0) return res;
        for(int i=1;i<=n;i++){
            dfs(nums,i,0,0,tmp);
        }
        return res;
    }
    void dfs(vector<int>& nums,int len,int idx,int curLen,vector<int>& tmp){
        if(curLen == len && idx<=nums.size()){res.push_back(tmp);return;}
        if((idx == nums.size()) && curLen<len){return;}
        for(int i=idx;i<nums.size();i++){
            tmp.push_back(nums[i]);
            dfs(nums,len,i+1,curLen+1,tmp);
            tmp.pop_back();
        }
    }
};