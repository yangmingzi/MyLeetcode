/*
举个例子
34 和 6
346要比634小，所以34***6也比6***34小，***可以是任何相同数字
也就是说其实顺序是固定的
所以要排序
然后为了防止大整数溢出，使用字符串
*/
class Solution {
public:
    static bool cmp(const string &s1, const string &s2) {
        return (s1 + s2) > (s2 + s1);
    }
    string largestNumber(vector<int> &num) {
        vector<string> s_num(num.size());
        for (int i = 0; i < num.size(); ++i) {
            s_num[i] = to_string(num[i]);
        }
        sort(s_num.begin(), s_num.end(), cmp);
        string res;
        bool flag = false;
        for (int i = 0; i < s_num.size(); ++i) {
            if (s_num[i] != "0") {
                res += s_num[i];
                flag = true;
            } else if (flag) {
                res += s_num[i];
            }
        }
        if (!flag) res.push_back('0');
        return res;
    }
};