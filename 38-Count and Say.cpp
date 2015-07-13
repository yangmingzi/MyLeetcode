/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
/*
题目描述的不是很清楚，其实就是第i+1个字符串是第i个字符串的读法，第一字符串为 “1”

比如第四个字符串是1211，它的读法是 1个1、1个2,2个1，因此第五个字符串是111221。

第五个字符串的读法是：3个1、2个2、1个1，因此第六个字符串是312211              

......

简单的模拟就可以。
其实我们可以发现字符串中永远只会出现1,2,3这三个字符，假设第k个字符串中出现了4，那么第k-1个字符串必定有四个相同的字符连续出现,
假设这个字符为1，则第k-1个字符串为x1111y。第k-1个字符串是第k-2个字符串的读法，
即第k-2个字符串可以读为“x个1,1个1,1个y” 或者“*个x,1个1,1个1,y个*”，
这两种读法分别可以合并成“x+1个1,1个y” 和 “*个x，2个1，y个*”，代表的字符串分别是“(x+1)11y” 和 "x21y"，
即k-1个字符串为“(x+1)11y” 或 "x21y"，不可能为“x1111y”.
*/
class Solution {
public:
    string countAndSay(int n) {
        if(n < 1)return "";
        string prev = "1";
        for(int i = 2; i <= n; i++)
        {
            char curChar = prev[0];
            int times = 1;//curChar 出现的次数
            string tmpstr;
            prev.push_back('#');//处理边界条件
            for(int k = 1; k < prev.size(); k++)
            {
                if(prev[k] == curChar)
                    times++;
                else
                {
                    tmpstr += to_string(times);
                    tmpstr.push_back(curChar);
                    curChar = prev[k];
                    times = 1;
                }
            }
            prev = tmpstr;
        }
        return prev;
    }
};