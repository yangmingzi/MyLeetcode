/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
/*分析：简单的处理二进制求和和进位即可 */
class Solution {
public:
    string addBinary(string a, string b) {
        int ia = a.size() - 1, ib = b.size() - 1;
        char carry = '0';
        string &res = (ia > ib)? a : b;
        int i = (ia > ib)? ia : ib;
        while(ia >= 0 && ib >= 0)
        {
            char tmp = carryBit(a[ia], b[ib], carry);
            res[i--] = charBitAdd(charBitAdd(a[ia--], b[ib--]), carry);
            carry = tmp;
        }
        while(i >= 0)
        {
            char tmp = carryBit(res[i], carry);
            res[i] = charBitAdd(res[i--], carry);
            carry = tmp;
        }
        if(carry == '0')return res;
        else return "1"+res;
    }
public:
    //求和函数
    char charBitAdd(char a, char b)
    {
        if(a == b)return '0';
        else return '1';
    }
    //求进位
    char carryBit(char add1, char add2, char carry = '0')
    {
        if((add1 == '1' && add2 == '1') ||
            (add1 == '1' && carry == '1') ||
            (add2 == '1' && carry == '1'))
            return '1';
        else return '0';
    }
};