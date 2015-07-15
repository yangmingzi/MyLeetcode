/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
/*简单的括号匹配问题，用栈来解决*/
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n == 0)return true;
        stack<char> sta;
        sta.push('#');
        for(int i = 0; i < n; i++)
        {
            switch(s[i])
            {
                case '(': sta.push('('); break;
                case '{': sta.push('{'); break;
                case '[': sta.push('['); break;
                case ')': {
                    char top = sta.top();
                    if(top != '(')return false;
                    else sta.pop();
                    break;}
                case '}': {
                    char top = sta.top();
                    if(top != '{')return false;
                    else sta.pop();
                    break;}
                case ']': {
                    char top = sta.top();
                    if(top != '[')return false;
                    else sta.pop();
                    break;}
            }
        }
        if(sta.size() == 1)return true;
        else return false;
    }
};