/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated.
 If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/
 /*
分析：首先需要知道哪些是合法的数字表示：比如 .2 , 2. 都是合法的小数表示，e的左右两边必须要有数字，还要注意正负号。
这个如果用正则表达式很简单，但是c++的标准库貌似还没有完全实现正则表达式模块（[-+]?(\\d+\\.?|\\.\\d+)\\d*(e[-+]?\\d+)? ）。
也可以自己写有限状态机来模拟正则表达式。

可以参考coder’s creed的博客有限状态机解法：http://www.cnblogs.com/chasuner/p/validNumber.html

unieagle的解法其实也是记录状态：http://blog.unieagle.net/2012/11/06/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Avalid-number/

下面的代码就是纯粹的判断，逻辑性太差
 */
class Solution {
public:
    bool isNumber(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(s.size()==0)return false;
        int len = s.size();
        int i = 0, j = len-1;
        while(i < len && s[i] == ' ')i++;//去掉首部空格
        if(i == len)return false;
        else if(s[i] == '-')i++;
        else if(s[i] == '+')i++;
        while(j >=0 && s[j] == ' ')j--;//去掉尾部空格
        len = j+1;
        int istart = i;
 
        while(i < len && s[i] >= '0' && s[i] <= '9')i++;
        if(i == len )
        {
            if(s[i-1] != '-' && s[i-1] != '+')return true;
            else return false;
        }
 
        if(s[i] == '.')
        {
            int doti = i;
            i++;
            while(i < len && s[i] >= '0' && s[i] <= '9')i++;
            if((doti == istart || s[doti-1] == '-' ||
                s[doti-1] == '+') && i == doti+1)return false;
            if(i == len)
                return true;
        }
 
        if(s[i] == 'e' || s[i] == 'E')
        {
            if(i == istart || s[i-1] == '-' || s[i-1] == '+')return false;
            if(s[++i] == '-' || s[i] == '+')i++;
            while(i < len && s[i] >= '0' && s[i] <= '9')i++;
            if(i == len)
            {
                if(s[i-1] < '0' || s[i-1] >'9')return false;
                return true;
            }
            else return false;
        }
        else return false;
    }
};