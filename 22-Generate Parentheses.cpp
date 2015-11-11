/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
/*
我们这样来构造一个合法的字符串：首先第一个位置肯定是“（”，对于后面位置:

1、如果前一个字符是“（”：那么我们可以在当前位置上加入“）”（字符“）”一定有剩余）；
如果“（”字符还有剩余，也可以在当前位置加入“（”  

2、如果前一个字符是“）”：如果当前“（”和“）”剩余的数目不同（即其那面的括号没有完全匹配），
可以在当前位置上加入“）”；如果“（”字符还有剩余，也可以在当前位置加入“（”

其实对于某个合法的字符串，
我们可以发现从合法字符串的任何一个位置看，“（”的数目 >= ")"的数目，
即剩余的“（”的数目 <= 剩余的"）"数目, 因此就有以下更加简洁的代码
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string tmpres;
        vector<string> res;
        helper(tmpres, res, n, n);
        return res;
    }
private:
    void helper(string &tmpres, vector<string>&res, int leftNum, int rightNum)
    {
        if(leftNum > rightNum)return;
        if(leftNum == 0 && rightNum == 0)
        {
            res.push_back(tmpres);
            return;
        }
        if(leftNum > 0)
        {
            tmpres.push_back('(');
            helper(tmpres, res, leftNum-1, rightNum);
            tmpres.pop_back();
        }
        if(rightNum > 0)
        {
            tmpres.push_back(')');
            helper(tmpres, res, leftNum, rightNum-1);
            tmpres.pop_back();
        }
    }
};
//二刷，自己做， 4 ms，12.58%
 class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        res.clear();
        if(n<1) return res;
        string cur="";
        cur.clear();
        dfs(n,0,0,cur);
        return res;
    }
    void dfs(int n,int left,int right,string& cur){
        if(left == n && right == n){res.push_back(cur);return;}
        if(n-left>n-right){return;}
        if(n-left>0){
            cur+="(";
            dfs(n,left+1,right,cur);
            cur = cur.substr(0,cur.size()-1);
        }
        if(n-right>0){
            cur+=')';
            dfs(n,left,right+1,cur);
            cur = cur.substr(0,cur.size()-1);
        }
    }
};