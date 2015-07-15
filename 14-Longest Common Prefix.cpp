/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
/*
题目的意思说的不是很清楚，开始理解成了求任意两个字符串的前缀中的最长者。
但是本题的意思是求所有字符串的最长公共前缀，即数组的所有字符串都包含这个前缀。
算法1：逐个字符比较，时间复杂度为O(N*L),N是字符串个数，L是最长前缀的长度
*/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        string res;
        if(n == 0)return res;
        for(int pos = 0; pos < strs[0].size(); pos++)//最长前缀的长度不超过strs[0].size()，逐个字符的比较
        {
            for(int k = 1; k < n; k++)//strs[0]的第pos个字符分别和strs[1...n-1]的第pos个字符比较
            {
                if(strs[k].size() == pos || strs[k][pos] != strs[0][pos])
                    return res;
            }
            res.push_back(strs[0][pos]);
        }
        return res;
    }
};
/*
算法2：第0个字符串和其他字符串逐个求前缀 ,
所有字符串的最长前缀长度 = min{ prefixLength(strs[0], strs[i]) ,  0 < i < n }  
算法2的时间复杂度是O(N*M),N是字符串个数，M = strs[0]和其他字符串的前缀长度的平均值, 
算法2中字符的比较次数要比算法1多。例如以下例子
strs[0]: abcdef
strs[1: abcde
strs[2: abcdk
strs[3]ab
按照算法1，只需要比较每个字符串的前3个字符；按照算法2，strs[0]和其他三个字符串分表需要比较6、5、3个字符
*/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        if(n == 0)return "";
        int len = strs[0].size();//最长前缀的长度
        for(int i = 1; i < n; i++)
        {
            int k;
            for(k = 0; k < min(len, (int)strs[i].size()); k++)
                if(strs[0][k] != strs[i][k])break;
            if(len > k)len = k;
        }
        return strs[0].substr(0, len);
    }
};