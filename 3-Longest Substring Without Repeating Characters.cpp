/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.
*/
/*
最长不重复子串
参考博客：http://www.ahathinking.com/archives/123.html
*/
/*
基本算法 使用Hash

要求子串中的字符不能重复，判重问题首先想到的就是hash，
寻找满足要求的子串，最直接的方法就是遍历每个字符起始的子串，辅助hash，
寻求最长的不重复子串，由于要遍历每个子串故复杂度为O(n^2)，n为字符串的长度，辅助的空间为常数hash[256]。
DP方案

前面刚刚讨论过最长递增子序列的问题，咋一想就觉得二者有点类似，何不向DP方面想一下，为什么说二者类似，
在LIS问题中，对于当前的元素，要么是与前面的LIS构成新的最长递增子序列，要么就是与前面稍短的子序列构成新的子序列或单独构成新子序列；

同理，对于最长不重复子串，某个当前的字符，如果它与前面的最长不重复子串中的字符没有重复，那么就可以以它为结尾构成新的最长子串；
如果有重复，且重复位置在上一个最长子串起始位置之后，那么就与该起始位置之后的稍短的子串构成新的子串或者单独成一个新子串。

举个例子：例如字符串“abcdeab”，第二个字符a之前的最长不重复子串是“abcde”，a与最长子串中的字符有重复，
但是它与稍短的“bcde”串没有重复，于是它可以与其构成一个新的子串，之前的最长重复子串“abcde”结束；

再看一个例子：字符串“abcb”，跟前面类似，最长串“abc”结束，第二个字符b与稍短的串“c”构成新的串；

这两个例子，可以看出些眉目：当一个最长子串结束时（即遇到重复的字符），
新的子串的长度是与第一个重复的字符的下标有关的，如果该下标在上一个最长子串起始位置之前，则dp[i] = dp[i-1] + 1，
即上一个最长子串的起始位置也是当前最长子串的起始位置；
如果该下标在上一个最长子串起始位置之后，则新的子串是从该下标之后开始的。

于是类似LIS，对于每个当前的元素，我们“回头”去查询是否有与之重复的，
如没有，则最长不重复子串长度+1，
如有，则考察上一个子串起始位置与重复字符下标的关系，
当然，如果DP使用O(n^2)的方案，则我们只需在内层循环遍历到上一个最长子串的起始位置即可，
O(N^2)的DP方案，我们可以与LIS的DP方案进行对比，是一个道理的。
DP + Hash 方案

上面的DP方案是O(n^2)的，之所以是n^2，是因为“回头”去寻找重复元素的位置了，受启发于最初的Hash思路，
我们可以用hash记录元素是否出现过，我们当然也可以用hash记录元素出现过的下标，
既然这样，在DP方案中，我们何不hash记录重复元素的位置，这样就不必“回头”了，
而时间复杂度必然降为O(N)，只不过需要一个辅助的常数空间visit[256]，典型的空间换时间。
这样遍历一遍便可以找到最长不重复子串
DP + Hash 优化方案

写到这里，还是有些别扭，因为辅助的空间多了，是不是还能优化，仔细看DP最优子问题解的更新方程：

1
dp[i] = dp[i-1] + 1;
dp[i-1]不就是更新dp[i]当前的最优解么？这与最大子数组和问题的优化几乎同出一辙，
我们不需要O(n)的辅助空间去存储子问题的最优解，而只需O(1)的空间就可以了，
至此，我们找到了时间复杂度O(N)，辅助空间为O(1)（一个额外变量与256大小的散列表）的算法，
注意：当前最长子串的构成是与上一次最长子串相关的，故要记录上一次最长子串的起始位置！
*/
/*
图中的start是一个标志位，表示当前不重复子串的起始位置，
图中的数字表示记录字符出现位置的数组hashtable，
比如字符b出现在第1位，那么hashtable[‘b’]=1。             

顺序扫描字符串，第4个位置时，在hashtable中发现b已经出现过（记出现的位置为k，此时k=1），
那么当前的不重复子串长度 = 当前位置-start；
下一个不重复子串就应该从第k+1个字符（2号位的c）开始，即令start = 2，
并且把[start, k)位置的字符对应的hashtable清空，重新设置b在hashtable的位置为4。
继续扫描直到再次发现相同的字符，和前面一样处理。
注意全部处理完字符串，还要判断一下末尾的不重复子串是否是最长的。

时间复杂度分析：最坏情况下，相当于遍历了两遍字符串，因此时间复杂度是O（n）
*/
//16ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> bitmap(128, -1);
        int res = 0;
        int start = 0, lastStart = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(bitmap[s[i]] != -1)
            {
                res = max(res, i-start);
                lastStart = start;
                start = bitmap[s[i]] + 1;
                for(int j = lastStart; j < bitmap[s[i]]; j++)
                    bitmap[s[j]] = -1;
            }
            bitmap[s[i]] = i;
        }
        res = max(res, (int)s.size()-start);//不要忘了最后的判断
        return res;
    }
};

//很巧妙地解法 16ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int locs[256];//保存字符上一次出现的位置
        memset(locs, -1, sizeof(locs));

        int idx = -1, max = 0;//idx为当前子串的开始位置-1
        for (int i = 0; i < s.size(); i++)
        {
            if (locs[s[i]] > idx)//如果当前字符出现过，那么当前子串的起始位置为这个字符上一次出现的位置+1
            {
                idx = locs[s[i]];
            }

            if (i - idx > max)
            {
                max = i - idx;
            }

            locs[s[i]] = i;
        }
        return max;
    }
};