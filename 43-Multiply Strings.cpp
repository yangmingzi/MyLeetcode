/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
/*
大整数乘法
这里采用的算法的复杂度为O（n^2）（假设整数长度为n）

另外更高效的计算大整数乘法一般有：
（1）karatsuba算法，复杂度为3nlog3≈3n1.585，可以参考百度百科、面试题——大整数乘法、乘法算法-Karatsuba算法。
（2）基于FFT(快速傅里叶变换)的算法，复杂度为o(nlogn), 可以参考FFT, 卷积, 多项式乘法, 大整数乘法
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        vector<int> tmpres(n1+n2, 0);
        int k = n1 + n2 - 2;
        for(int i = 0; i < n1; i++)
            for(int j = 0; j < n2; j++)
                tmpres[k-i-j] += (num1[i]-'0')*(num2[j]-'0');
        int carryBit = 0;
        for(int i = 0; i < n1+n2; i++)//处理进位
        {
            tmpres[i] += carryBit;
            carryBit = tmpres[i] / 10;
            tmpres[i] %= 10;
        }
        int i = k+1;
        while(tmpres[i] == 0)i--;//去掉乘积的前导0
        if(i < 0)return "0"; //注意乘积为0的特殊情况
        string res;
        for(; i >= 0; i--)
            res.push_back(tmpres[i] + '0');
        return res;
    }
};