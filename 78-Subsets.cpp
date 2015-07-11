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