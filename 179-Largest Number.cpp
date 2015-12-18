/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/
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
//
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for_each(nums.begin(),nums.end(),[&](int i) {
            strs.push_back(to_string(i));
        });
        sort(strs.begin(),strs.end(),[&](const string& a,const string& b){
            return (a+b)>(b+a);
        });
        string ans = "";
        for_each(strs.begin(),strs.end(),[&](string i){
            if(ans=="" && i=="0") return;
           ans += i;
        });
        return ans==""?"0":ans;
    }
};