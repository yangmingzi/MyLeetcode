/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> dic;
        map<string,char> mp;
        map<char,string> mp1;
        int len = pattern.size();
        int pre = 0;
        istringstream sin(str);
        string tmp;
        while (sin >> tmp) dic.push_back(tmp);
        if (dic.size() != pattern.size()) return false;
        for(int i=0;i<len;i++){
            if(mp1.find(pattern[i])==mp1.end() && mp.find(dic[i])==mp.end()){
                mp1[pattern[i]] =dic[i];
                mp[dic[i]] = pattern[i];
            }else{
                if(mp1[pattern[i]]!=dic[i] || mp[dic[i]]!=pattern[i]){
                    return false;
                }
            }
        }
        return true;
    }
};