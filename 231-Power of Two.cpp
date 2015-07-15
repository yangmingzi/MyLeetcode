/*
Given an integer, write a function to determine if it is a power of two.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
/*
很简单的要求，不过一开始我居然没有想到解决问题的办法，
用一种很傻的方法做的，后来感觉不对，看了提示，用位运算解决，才恍然大悟，用简单方法解决了问题。。
power of 2的数看十进制，没有什么特别的地方，
但是转换成二进制之后，都是100000的形式，最高位是1，其余位都是0，
然后，这个数减1，就变为011111，最高位（已消失）为0，之后都是1，
所以这两个数按位与(&)则变为0000000000.。。根据这个特性，可以解决这道题，代码如下:
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        return !(n & (n-1));
    }
};
/*
这道题的题意是判断一个数是不是2的幂。有几个问题需要确定一下：

1、1也是2的幂，是0次幂

2、将一个整数向左移一位，相当于这个整数乘以2，向右移一位，相当于该整数除以2

3、注意大整数的溢出情况。
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long num = 1;
        while(num <= n){
            if(num==n){ //先判断，考虑到1的情况
                return true;
            }
            num = num << 1;
        }
        return false;
    }
};