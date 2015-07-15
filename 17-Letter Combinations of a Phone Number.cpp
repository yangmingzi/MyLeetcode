/*
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

//递归DFS解法
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length()==0) return res;
        string tmpres(digits.size(), ' ');
        dfs(digits, 0, tmpres, res);
        return res;
    }
     
    void dfs(const string &digits, int index, string &tmpres, vector<string>&res)
    {
        string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(index == digits.size())
        {
            res.push_back(tmpres);
            return;
        }
        for(int i = 0; i < numap[digits[index] - '0'].size(); i++)
        {
            tmpres[index] = numap[digits[index] - '0'][i];
            dfs(digits, index+1, tmpres, res);
        }
    }
};
//非递归DFS解法
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.length()==0) return res;
        vector<int> ansIndex(digits.size(), 0);
        string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        while(true)
        {
            string tmp(digits.size(),' ');
            for(int i = 0; i < digits.size(); i++)
                tmp[i] = numap[digits[i]-'0'][ansIndex[i]];
            res.push_back(tmp);
            int k = digits.size() - 1;
            while(k >= 0)
            {
                if(ansIndex[k] < numap[digits[k]-'0'].size() - 1)
                {
                    ansIndex[k]++;
                    break;
                }
                else 
                {
                    ansIndex[k] = 0;
                    k--;
                }
            }
            if(k < 0)break;
        }
        
        return res;
    }
};
//bfs非递归解法（类似于求集合子集的算法2）  
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res(1,"");
        if(digits.length()==0) return res;
        string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i = 0; i < digits.size(); i++)
        {
            vector<string>tmp;
            for(int j = 0; j < res.size(); j++)
                for(int k = 0; k < numap[digits[i] - '0'].size(); k++)
                    tmp.push_back(res[j] + numap[digits[i] - '0'][k]);
            res = tmp;
        }
         
        return res;
    }
};