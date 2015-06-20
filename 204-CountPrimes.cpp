//厄哆拉塞筛法
//从第一个素数开始把它的倍数去掉，那么下一个没有被去掉的数一定是素数，重复上面的过程。
//这篇博客讲得非常好，从算法到优化：http://www.cnblogs.com/easonliu/p/4461701.html
class Solution {
public:
    int countPrimes(int n) {
        bool *tag = new bool[n];
        int *prime = new int[n];//使用数组，极大的提高效率
        int cnt = 0;
        memset(tag, true, sizeof(bool) * n);
        for (int i = 2; i < n; ++i) {
            if (tag[i]) prime[cnt++] = i;
            for (int j = 0; j < cnt && i * prime[j] < n; ++j) {
                tag[i * prime[j]] = false;
                //这里非常有意思，剪枝
                //如果i可以整除任何prime[J]，那么就没有必要在继续试验了以后的prime[j](j>J)了
                //当i=15时，i%3=0，虽然i*5=75,但是75早在i=3的时候就被筛掉了
                //如果i=prime*x，那么i*y = prime[j]*x*y，i的整数倍早就在prime[j]时就被筛掉了
                if (i % prime[j] == 0) break;
            }
        }
        delete [] tag;//好的变成习惯，不释放也可以AC
        delete [] prime;
        return cnt;
    }
};