//搜索出所有答案，所以想到dfs
//参照dfs模板
//另外，此题题意和测试用例 不相符
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
    	
        vector<int> path;
        vector<vector<int>> res;
        dfs(k,n,1,0,0,&path,&res);//6 [0,6],
        return res;
    }

    void dfs(int k,int n,int idx,int sum,int cnt,vector<int> &path,  vector<vector<int>> &res)
    {
    	if(sum>n||idx>10||cnt>k) return; //idx从0开始，所以要求大于10
    	if(sum==n&&cnt==k){res.push_back(path);return;} 
    	dfs(k,n,idx+1,sum,cnt,path,res);//不使用idx
    	path.push_back(idx);
    	dfs(k,n,idx+1,sum+idx,cnt+1,path,res);//使用idx
    	path.pop_back();
    }
};
