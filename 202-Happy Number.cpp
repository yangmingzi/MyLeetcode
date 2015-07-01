//为什么：n!=4 in line7
//参见维基百科：https://en.wikipedia.org/wiki/Happy_number
//If n is not happy, then its sequence does not go to 1. Instead, it ends in the cycle:
//4, 16, 37, 58, 89, 145, 42, 20, 4, ...
//也可以用Hash的方法解决“检测陷入循环”的问题，
//解题思路：一开始直接模拟，循环100次还不是1直接剪掉return false，也能AC，
//但是毕竟可能有情况覆盖不到，改用HastSet存放中间数就行了，如果得到的新结果在中间数集合中出现了，那么一定会陷入循环并且得到的不是1
//参考博客：http://www.cnblogs.com/aboutblank/p/4446565.html
class Solution {
public:
    bool isHappy(int n) {
        int tmp, dig;
        while (n != 4) {
            tmp = 0;
            while (n > 0) {
                dig = n % 10;
                tmp += dig * dig;
                n /= 10;
            }
            n = tmp;
            if (n == 1) return true;
        }
        return false;
    }
};