/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example, 
S = "ADOBECODEBANC" 
T = "ABC"

Minimum window is "BANC".

Note: 
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/
/*
分析：暴力解决可以在O（n^2）时间复杂度内完成：
遍历S，当碰到T中的首字母时，以该字母为窗口起始位置找到一个最小窗口包含所有T中的字符，最后取所有窗口的最小值。
在暴力方法中我们做了很多重复的事情，比如S = “aabc”,T = “abc”,当我们以第一个a为窗口起始位置遍历时，我们要判断b、c是否在T中，
当我们以第二个a为窗口起始位置遍历时，我们还要判断b、c是否在T中。那么怎样避免这种重复的工作呢？ 本文地址

可以利用两个指针扫描（两个指针分别为start，i），以S = “e b a d b a c c b”（忽略空格），T = “abc”为例：
                                                                            0 1 2 3 4 5 6 7 8
初始化 start = i = 0
i 逐渐往后扫描S直到窗口S[start…i]包含所有T的字符，此时i = 6（字符c的位置）
缩减窗口：此时我们注意到窗口并不是最小的，需要调整 start 来缩减窗口。
缩减规则为：如果S[start]不在T中 或者 S[start]在T中但是删除后窗口依然可以包含T中的所有字符，那么start = start+1， 直到不满足上述两个缩减规则。
缩减后i即为窗口的起始位置，此例中从e开始窗口中要依次删掉e、b、a、d，start最后等于4 ，那么得到一个窗口大小为6-4+1 = 3
start = start+1(此时窗口肯定不会包含所有的T中的字符)，跳转到步骤2继续寻找下一个窗口。本例中还以找到一个窗口start = 5，i = 8，比上个窗口大，因此最终的最小窗口是S[4…6]
具体实现时，要用哈希表来映射T中字符以便在O(1)时间内判断一个字符是否在T中，
由于是字符缘故，可以用数组简单的来实现；还需要一个哈希表来记录扫描时T中的某个字符在S中出现的次数，也可以用数组实现

小小改进：注意到上述步骤3中缩减窗口时start要跳过不在T中的字符，如果S = “eeeeeeeeebadbaccb”（S的前面有大量的字符e不在T中），T = “abc”，
这个跳转会很费时，如果可以在第2步i扫描的过程中保存好T中字符在S中出现的位置，
那么我们在缩减窗口时就不需要跳过例子中大量的e，只需要跳过b、a这些在T中存在但是不影响窗口的字符。这个可以用辅助队列来实现。
*/
class Solution {
public:
    string minWindow(string S, string T) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int lens = S.size(), lent = T.size();
        queue<int> Q;
        int srcCnt[256] = {0};//T中每个字母的个数
        int foundCnt[256] = {0};//当前找到T中每个字母的个数
        for(int i = 0; i < lent; i++)
            srcCnt[T[i]]++;
        int hasFound = 0;//已经找到的字母数目
        int winStart = -1, winEnd = lens;//窗口的左右边界
        for(int i = 0; i < lens; i++)
            if(srcCnt[S[i]] != 0)
            {
                Q.push(i);
                foundCnt[S[i]]++;
                if(foundCnt[S[i]] <= srcCnt[S[i]])hasFound++;
                if(hasFound == lent)
                {//找到了一个满足的窗口
                    int k;
                    do
                    {//缩减窗口到最小
                        k = Q.front();
                        Q.pop();
                        foundCnt[S[k]]--;
                    }
                    while(srcCnt[S[k]] <= foundCnt[S[k]]);
                    //替换原来的值
                    if(winEnd - winStart > i - k)
                    {
                        winStart = k;
                        winEnd = i;
                    }
                    hasFound--;
                }
            }
        return winStart != -1 ? S.substr(winStart, winEnd - winStart +1) : "";
    }
};