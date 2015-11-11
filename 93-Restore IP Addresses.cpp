/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
//4ms,15.90%
class Solution {
public:
    bool isVail(string s) {
        if (s.length() != 1 && s[0] == '0') 
            return false;
        int n = s[0] - '0';
        for (int i = 1; i < s.size(); ++i) {
            n *= 10;
            n += (s[i] - '0');
        }
        return n <= 255;
    }
    
    void findNext(vector<string> &res, string &s, string substr, int cnt, int idx) {
        if (cnt < 4 && cnt > 0) 
            substr.push_back('.');
        if (cnt == 4 && idx == s.length()) {
            res.push_back(substr);
            return;
        } else if (cnt == 4 && idx != s.length()) {
            return;
        }
        
        string digit;
        for (int len = 1; len <= 3 && idx + len <= s.length(); ++len) {
            digit = s.substr(idx, len);
            if (isVail(digit)) {
                findNext(res, s, substr + digit, cnt + 1, idx + len);
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        findNext(res, s, "", 0, 0);
        return res;
    }
};
//二刷，自己做的,4ms,15.90%
class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if(s.size()<4 && s.size()>12) return res;
        string tmp="";
        dfs(s,0,0,tmp);
        return res;
    }
    void dfs(string s,int idx,int cnt,string& cur){
        if(cnt==4 && idx==s.size()){res.push_back(cur);return;}
        if(cnt==4 && idx!=s.size()){return;}
        int tmpLen = s.size()-idx;
        if(tmpLen>3) {tmpLen=3;}
        for(int i=1;i<=tmpLen;i++){
            string tmp;
            string tmpIp = s.substr(idx,i);
            if(check(tmpIp)){
                tmp=cur+s.substr(idx,i);
                if(cnt != 3){
                    tmp=tmp +'.';
                    dfs(s,idx+i,cnt+1,tmp);
                }else{
                    dfs(s,idx+i,cnt+1,tmp);   
                }
            }else{
                continue;
            }
        }
    }
    bool check(string ip)
    {
        int value = stoi(ip);
        if(ip[0] == '0')
        {
            return (ip.size() == 1);
        }
        else
        {
            if(value <= 255)
                return true;
            else
                return false;
        }
    }
};