/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/
/*
这个题目是求一个正整数用二进制表示后其中的1的个数。
看到题目后不难想到只要让其循环移位，每次和0x01做与操作，统计1的个数即可。
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while(n!=0)
        {
            if(n&0x01)
            ++result;
            n = n>>1;
        }
        return result;
    }
};
//
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
           if(n%2 == 1){
               res++;
           }
           n /= 2;
        }
        return res;
    }
};