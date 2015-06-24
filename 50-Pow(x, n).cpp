//关于这道题的误区，这篇博客很详细http://www.cnblogs.com/lautsie/p/3242224.html
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) return 1 / (myPow(x,-(n+1))*x);//不是(-n+1)，注意符号，论单步调试的重要性
        double e = myPow(x, n / 2);
        if (n % 2 == 0) {
            return e * e;;
        } else {
            return x * e * e;
        }
    }
};