/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
  */
class Solution {
public:
    //判断是否回文
    bool isPail(string &s) {
        int low = 0, high = s.length() - 1;
        while (low < high) {
            if (s[low] != s[high]) {
                return false;
            }
            ++low;
            --high;
        }
        return true;
    }
    //深搜
    void findNext(vector<vector<string> > &res, string &s, vector<string> part, int idx) {
        if (idx == s.length()) {
            res.push_back(part);
            return;
        }
        string substr;
        for (int len = s.length() - idx; len > 0; --len) {
            substr = s.substr(idx, len);
            if (isPail(substr)) {
                part.push_back(substr);
                findNext(res, s, part, idx + len);
                part.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> part;
        findNext(res, s, part, 0);
        return res;
    }
};
//二刷，自己做出来的，28ms 和一刷一样的速度,34.55%
class Solution {
public:
    bool isPal(string s){
        if(s.size()==1) return true;
        int n = s.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return  true;
    }
    void dfs(string s,int index,vector<string> &part,vector<vector<string>> &res){
        if (index == s.size()){
            res.push_back(part);
            return;
        }
        string tmp;
        for(int i=1;index+i<=s.size();i++){
            tmp = s.substr(index,i);
            if(isPal(tmp)){
                part.push_back(tmp);
                dfs(s,index+i,part,res);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        dfs(s,0,part,res);
        return res;
    }
};