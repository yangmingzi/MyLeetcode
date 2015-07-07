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