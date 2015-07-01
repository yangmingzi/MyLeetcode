//字典+位运算，或者进制转换。
//由于直接将字符串存入字典会导致Memory Limit Exceeded，采用位操作将字符串转化为整数可以减少内存开销。
//不知用KMP是否可行？以后有机会试一下。估计会超时。
class Solution {
public:
    int getVal(char ch) {
        if (ch == 'A') return 0;
        if (ch == 'C') return 1;
        if (ch == 'G') return 2;
        if (ch == 'T') return 3;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> st;
        vector<string> res;
        string str;
        if (s.length() < 10 || s == "") return res;
        int mp[1024*1024] = {0};
        unsigned int val = 0;
        //得到最开始9个基因的串
        for (int i = 0; i < 9; ++i) {
            val <<= 2;
            val |= getVal(s[i]);
        }
        //哈希表映射，10个基因串20位二进制，1024种可能
        //每次滑动一个基因，获得一个长度为10的基因串，然后将该串哈希
        //哈希值大于1的时候证明该串出现过，送入s中
        for (int i = 9; i < s.length(); ++i) {
            val <<= 14;
            val >>= 12;
            val |= getVal(s[i]);
            ++mp[val];
            if (mp[val] > 1) {
                str = s.substr(i-9, 10);
                st.insert(str);
            }
        }
        //s为set，自动去重，最后将结果送入的返回的vector中
        for (set<string>::iterator i = st.begin(); i != st.end(); ++i) {
            res.push_back(*i);
        }
        return res;
    }
};