/*
二进制转格雷码：gray = (binary) xor (binary >> 1)
参见博客：http://www.cnblogs.com/TenosDoIt/p/3451938.html
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        //注意n = 0时，输出{0}而不是空数组
        int num = 1<<n;
        vector<int> res;
        res.reserve(num);
        for(int i = 0; i < num; i++)
            res.push_back(i^(i>>1));
        return res;
    }
};