/*
Determine whether an integer is a palindrome. Do this without extra space.
Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, 
if you have solved the problem "Reverse Integer", 
you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/
/*
注意：oj里面把负数视为非回文数
提示里面说可以把数字倒转过来，如果和原来数字相同那么就是回文数，
但是数字倒转后可能越界，比如2147483647倒转后7463847412就超过了无符号整数的最大值  
只能逐个比较整数的第一个字符和最后一个字符，比如12321 第一次比较成功后数字变为232，再次比价后变为3
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        int len = integerLength(x);
        int factor1 = pow(10, len-1);
        while(x != 0)
        {
            if(x / factor1 != x % 10)
                return false;
            x %= factor1;
            x /= 10;
            factor1 /= 100;
        }
        return true;
    }
     
    //求整数x的长度 
    int integerLength(int x)
    {
        int res = 0;
        while(x)
        {
            x /= 10;
            res++;
        }
        return res;
    }
};