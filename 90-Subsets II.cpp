/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
//子集思想总结：http://www.cnblogs.com/felixfang/p/3775712.html
//参考博客（提供多种解法）：http://www.cnblogs.com/TenosDoIt/p/3451902.html
/*
dfs解法。
注意到处理第三个元素2时，因为前面已经处理了一次2，
所有第三层中，我们只在已经添加过2的集合{1,2}、{2}上再添加2，
而没有在集合{1}, {}上添加2（画叉叉的那么分支），
假设下面还有一个2，那么我们只在第四层的包含两个2的集合{1,2,2}、{2,2}上再添加2，其它都不添加。
因此dfs时，如果当前处理的数字前面出现了k次，那么我们要处理的集合中必须包含k个该元素。代码如下：
*/
//16ms
class Solution {
private:
    vector<vector<int> >res;
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //先排序，然后dfs每个元素选或者不选，最后叶子节点就是所有解。
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
        int firstSame = iend;
        while(firstSame >=0 && S[firstSame] == S[iend])firstSame--;
        firstSame++; //firstSame是第一个和S[iend]相同数字的位置
        int sameNum = iend - firstSame;//和S[iend]相同数字的个数(除自己)
        if(sameNum == 0 ||
            (tmpres.size() >= sameNum && tmpres[tmpres.size() - sameNum] == S[iend]))//因为前面先排序了
        {
            //选择S[iend]
            tmpres.push_back(S[iend]);
            dfs(S, iend+1, tmpres);
            tmpres.pop_back();
        }
        //不选择S[iend]
        dfs(S, iend+1, tmpres);
    }
};

//二刷，8ms
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        dfs(nums,res,tmp,0);
        return res;
    }
    void dfs(vector<int> &nums,vector<vector<int>> &res,vector<int> &tmp,int dep){
        res.push_back(tmp);
        for(int i=dep;i<nums.size();i++){
            if(i!=dep&&nums[i]==nums[i-1]){continue;}
            tmp.push_back(nums[i]);
            dfs(nums,res,tmp,i+1);
            tmp.pop_back();
        }
    }
};