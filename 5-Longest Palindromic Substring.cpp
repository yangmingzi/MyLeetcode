/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
//马拉车算法Manncher
//最简单的写法
class Solution {
public:
    string longestPalindrome(string s) {
        string t="$#";
        for(int i=0;i<s.size();i++){
            t+=s[i];
            t+="#";
        }
        int p[t.size()]={0};
        int mx=0,id=0,resId=0,resMx=0;
        for(int i=0;i<t.size();i++){
            p[i]=mx>i?min(p[2*id-i],mx-i):1;
            while(t[i-p[i]]==t[i+p[i]]) ++p[i];
            if(mx<i+p[i]){
                mx=i+p[i];
                id=i;
            }
            if(p[i]>resMx){
                resMx=p[i];
                resId=i;
            }
        }
        return s.substr((resId-resMx)/2,resMx-1);
    }
};
/*
class Solution {
public:
    string longestPalindrome(string s) {
        const int len = s.size();
        if(len <= 1)return s;
        //Manncher算法 ，o（n）
        string str = preProcess(s);
        int n = str.size(), id = 0, mx = 0;
        vector<int>p(n, 0);
        for(int i = 1; i < n-1; i++)
        {
            p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;
            //if(mx <= i || (mx > i && p[2*id-i] == mx - i)) //根据正文斜体部分的注释，这里可要可不要
            while(str[i+p[i]] == str[i-p[i]])p[i]++;
            if(i + p[i] > mx)
            {
                mx = i + p[i];
                id = i;
            }
        }
         
        //遍历p，寻找最大回文长度
        int maxLen = 0, index = 0;
        for(int i = 1; i < n-1; i++)
            if(p[i] > maxLen)
            {
                maxLen = p[i];
                index = i;
            }
        return s.substr((index - maxLen)/2, maxLen-1);
    }
    //预处理字符串，abc预处理后变成$#a#b#c#^
    string preProcess(const string &s)
    {
        int n = s.size();
        string res; 
        res.push_back('$');//把$放到字符串头部
        res.push_back('#');//以#作为原来字符串中每个字符的间隔
        for(int i = 0; i < n; i++)
        {
            res.push_back(s[i]);
            res.push_back('#');
        }
        res.push_back('^');//以^作为字符串的结尾
        return res;
    }
};
*/
/*
解法一
// Time complexity O(n*n)
class Solution {
public:
    string longestPalindrome(string s) {
        int startIdx = 0, left = 0, right = 0, len = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == s[i + 1]) {
                left = i;
                right = i + 1;
                searchPalindrome(s, left, right, startIdx, len);
            }
            left = right = i;
            searchPalindrome(s, left, right, startIdx, len);
        }
        if (len == 0) len = s.size();
        return s.substr(startIdx, len);
    }
    void searchPalindrome(string s, int left, int right, int &startIdx, int &len) {
        int step = 1;
        while ((left - step) >= 0 && (right + step) < s.size()) {
            if (s[left - step] != s[right + step]) break;
            ++step;
        }
        int wide = right - left + 2 * step - 1;
        if (len < wide) {
            len = wide;
            startIdx = left - step + 1;
        }
    }
};
*/
/*

此题还可以用动态规划Dynamic Programming来解，根Palindrome Partitioning II 拆分回文串之二的解法很类似，我们维护一个二维数组dp，其中dp[i][j]表示字符串区间[i, j]是否为回文串，当i = j时，只有一个字符，肯定是回文串，如果i = j + 1，说明是相邻字符，此时需要判断s[i]是否等于s[j]，如果i和j不相邻，即i - j >= 2时，除了判断s[i]和s[j]相等之外，dp[j + 1][i - 1]若为真，就是回文串，通过以上分析，可以写出递推式如下：

dp[i, j] = 1                                               if i == j

           = s[i] == s[j]                                if j = i + 1

           = s[i] == s[j] && dp[i + 1][j - 1]    if j > i + 1      

这里有个有趣的现象就是如果我把下面的代码中的二维数组由int改为vector<vector<int> >后，就会超时，这说明int型的二维数组访问执行速度完爆std的vector啊，所以以后尽可能的还是用最原始的数据类型吧。
*/
// DP
class Solution {
public:
    string longestPalindrome(string s) {
        int dp[s.size()][s.size()] = {0}, left = 0, right = 0, len = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if (dp[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = 1;
        }
        return s.substr(left, right - left + 1);
    }
};