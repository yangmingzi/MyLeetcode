// Manacher算法
//求出以第一个字母为起点的最长回文串，然后在字符串前方倒序填充剩余部分
//Manacher算法参考链接：http://www.cnblogs.com/biyeymyhjob/archive/2012/10/04/2711527.html
class Solution {
public:
    int longestPalindrom(string s) {
        //预处理
        string s1;
        s1.resize(2 * s.length() + 2);
        int idx = 0;
        s1[idx++] = '$';
        s1[idx++] = '#';
        for (char a : s) {
            s1[idx++] = a;
            s1[idx++] = '#';
        }
        //p[i]-1恰好就是原字符串中的回文串长度
        vector<int> p(s1.length(), 0);
        int res = 0;
        for (int id = 0, i = 1; i < s1.length(); ++i) {
            int mx = id+p[id];//最大回文子串的边界
            //选取i，如果不在当前最大回文内，则p[i]=1.若在，利用对称性获得临时的p[i]
            if (i < mx){ 
                p[i] = min(p[2 * id - i], mx - i);//id表示最大回文子串的中心位置
            }
            else p[i] = 1;
            //扩展以p[i]为中心的回文数组
            while (s1[i + p[i]] == s1[i - p[i]]) ++p[i];
            //所有回文串都以以第一个字符为起点，所以下面可以这样替换
            if (mx < i + p[i]) id = i;
            if (p[i] == i) res = max(res, i);
        }
        //最终返回的是回文串终点在子串的位置
        return res - 1;
    }
    
    string shortestPalindrome(string s) {
        int pos = longestPalindrom(s);
        string res;
        //倒序填充非回文部分
        for (int i = s.length() - 1; i >= pos; --i) res.push_back(s[i]);
        return res + s;
    }
};