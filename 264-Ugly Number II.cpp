/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/
/*
最普通（也最耗时）的做法是从1开始遍历，
然后判断这个数的因式分解中只包含2,3,5，满足则找到了一个，一直找下去，直到第n个被找出！
测试了一下，找第1500个丑数耗时40秒！

分析：假设数组ugly[N]中存放不断产生的丑数，初始只有一个丑数ugly[0]=1，
由此出发，下一个丑数由因子2,3,5竞争产生，得到ugly[0]*2, ugly[0]*3, ugly[0]*5， 
显然最小的那个数是新的丑数，所以第2个丑数为ugly[1]=2，
开始新一轮的竞争，由于上一轮竞争中，因子2获胜，这时因子2应该乘以ugly[1]才显得公平，
得到ugly[1]*2,ugly[0]*3,ugly[0]*5， 因子3获胜，ugly[2]=3，
同理，下次竞争时因子3应该乘以ugly[1]，即：ugly[1]*2, ugly[1]*3, ugly[0]*5, 
因子5获胜，得到ugly[3]=5，重复这个过程，直到第n个丑数产生。
总之：每次竞争中有一个（也可能是两个）因子胜出，下一次竞争中 胜出的因子就应该加大惩罚！

*/
 Solution {
public:
    int mymin(int a,int b,int c){
        int temp = (a<b?a:b);
        return (temp<c?temp:c);
    }
    int nthUglyNumber(int n) {
        if(n==0) return 0;
        int *ugly = new int[n];
        ugly[0] = 1;
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        int index  = 1;
        while(index<n){
            int val = mymin(ugly[index2]*2,ugly[index3]*3,ugly[index5]*5);
            if(val == ugly[index2]*2) ++index2;
            if(val == ugly[index3]*3) ++index3;
            if(val == ugly[index5]*5) ++index5;
            ugly[index++] = val;
        }
        int result = ugly[n-1];
        delete[] ugly;
        return result;
    }
};
//
class Solution {
public:
    bool isUgly(int num) {
        if(num==0) return false;
        while(num%2 == 0){
            num /=2;
        }
        while(num%3 == 0){
            num /= 3;
        }
        while(num%5 == 0){
            num /= 5;
        }
        return num==1?true:false;
    }
};