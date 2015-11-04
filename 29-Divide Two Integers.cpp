/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/
/*
这道题让我们求两数相除，而且规定我们不能用乘法，除法和取余操作，
那么我们还可以用另一神器位操作Bit Operation，
思路是，
如果被除数大于或等于除数，则进行如下循环，定义变量k等于除数，定义计数i，
当k小于等于被除数时，进行如下循环，被除数自减k，k向左平移一位，结果res自增1向左平移i位，i自增1。
这道题的OJ给的一些test case非常的讨厌，因为输入的都是int型，
比如被除数是-2147483648，在int范围内，当除数是-1时，结果就超出了int范围，需要返回INT_MAX，
所以对于这种情况我们就在开始用if判定，将其和除数为0的情况放一起判定，返回INT_MAX。
然后我们还要根据被除数和除数的正负来确定返回值的正负，
这里我们采用长整型long来完成所有的计算，最后返回值乘以符号即可，代码如下：
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        long m = labs(dividend), n = labs(divisor), res = 0;
        long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if (n == 1) return m * sign;//这里也都要用labs后的除数和被除数
        while (m >= n) {
            long k = n;//这里写成int就会超时
            int i = 0;
            while (k <= m) {
                m -= k;
                k <<= 1;
                res += 1 << i;
                ++i;
            }
        }
        return (res * sign);
    }
};

