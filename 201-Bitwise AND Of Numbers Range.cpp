/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/
/*
我们再来看一个范围[26, 30]，它们的二进制如下
11010　　11011　　11100　　11101　　11110
发现了规律后，我们只要写代码找到左边公共的部分即可
(1)我们可以从建立一个32位都是1的mask，然后每次向左移一位，
比较m和n是否相同，不同再继续左移一位，直至相同，然后把m和mask相与就是最终结果，
(2)此题还有另一种解法，不需要用mask，直接平移m和n，每次向右移一位，直到m和n相等，
记录下所有平移的次数i，然后再把m左移i位即为最终结果，
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m>n){
            return 0;
        }
        int i=0;
        while(m!=n&&m!=0){
            m >>= 1;
            n >>= 1;
            i++;
        }
        return m<<i;
    }
};