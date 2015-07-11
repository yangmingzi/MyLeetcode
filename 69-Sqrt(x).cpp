//牛顿法，参考博客：http://www.cnblogs.com/TenosDoIt/p/3471926.html
/*
面试时需要考虑x是否小于0.
分析：牛顿法，先假设一个初始解res（本文设为1），
然后以抛物y = x^2-c（这里的c相当于题目中的x）上的点(res, res^2-c)为切点作切线，
让res = 切线与x轴的交点，一直循环上面的操作直到前后两次的解相同。        
*/
class Solution {
public:
    int mySqrt(int x) {
        double res = 1.0, tmpres = 0.0;
        while(int(res) - int(tmpres))
        {
            tmpres = res;
            //res / 2.0 + x /(2.0 * res)为切线与x轴的交点
            res =  res / 2.0 + x /(2.0 * res);
        }
        return (int)res;
    }
};