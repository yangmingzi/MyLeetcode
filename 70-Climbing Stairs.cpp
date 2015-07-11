//参考博客：http://www.cnblogs.com/TenosDoIt/p/3465356.html
class Solution {
public:
    int climbStairs(int n) {
        int fbn1 = 0, fbn2 = 1;
        for(int i = 1; i <= n; i++)
        {
            int tmp = fbn1 + fbn2;
            fbn1 = fbn2;
            fbn2 = tmp;
        }
        return fbn2;
    }
};