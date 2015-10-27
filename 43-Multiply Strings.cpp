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
//8ms,48.92%
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

//二刷 8ms,48.92%
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1=num1.length(), len2=num2.length();
        if ( (len1==1 && num1=="0") || (len2==1 && num2=="0"))
            return "0";
        int *ans = new int[len1+len2], k=0;
        memset(ans, 0, (len1+len2)*sizeof(int));

        for (int i=len1-1; i>=0; i--)
            for (int j=len2-1; j>=0; j--)
                ans[len1-1-i + len2-1-j] += (num1[i]-'0')*(num2[j]-'0');

        for (int i=0; i<len1+len2-1; i++)
            ans[i+1] += ans[i]/10, ans[i] %= 10;

        string ret;
        for (int i=len1+len2-1; i>=0; i--)
            ret += to_string(ans[i]);

        while (k<ret.length() && ret[k]=='0') k++;
        return ret.substr(k, ret.length()-k);

    }
};

//
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        string sum(len1+len2,0);
        for(int i = len1-1;i>=0;i--){
            int carry = 0;
            for(int j = len2-1;j>=0;j--){
               int tmp = (sum[i+j+1])+(num1[i]-'0')*(num2[j]-'0')+carry;
                carry = tmp/10 ;
               sum[i+j+1]  = tmp - carry*10;
              
            }
            sum[i]+=carry;
        }
        
        size_t t = sum.find_first_not_of('\0');
        if(string::npos != t){
            for(int i=t;i<sum.size();i++){
                sum[i]+='0';
            }
             return sum.substr(t);
        }
        return "0";
    }
};

//
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        string sum(len1+len2,'0');
        for(int i = len1-1;i>=0;i--){
            int carry = 0;
            for(int j = len2-1;j>=0;j--){
               int tmp = (sum[i+j+1]-'0')+(num1[i]-'0')*(num2[j]-'0')+carry;
               sum[i+j+1]  = tmp%10 +'0';
               carry = tmp/10 ;
            }
            sum[i]+=carry;
        }
        
        size_t t = sum.find_first_not_of("0");
        if(string::npos != t){
             return sum.substr(t);
        }
        return "0";
    }
};
//
class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.length(), l2=num2.length(),carry = 0;;
        if(num1=="0" || num2=="0") return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res(l1+l2,0);
        for(int len=1; len<=l1+l2; ++len){
            for(int i=0; i<len&&i<l1; ++i){
                if(len-i-1 <l2) carry += (num1[i]-'0')*(num2[len-i-1]-'0');
            }
            res[len-1]=(carry%10)+'0';
            carry /= 10;
        }
        if(res[res.length()-1]=='0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};