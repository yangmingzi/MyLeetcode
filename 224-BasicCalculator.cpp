/*
一个栈存储数字，一个栈存储运算符
特殊测试用例：
1+1
(1)
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> stk_val;
        stack<char> stk_op;
        int res = 0, tmp;
        for (int i = 0; i <= s.length(); ++i) {
            //操作数
            if (i < s.length() && isdigit(s[i])) {
                res = 0;
                while (i < s.length() && isdigit(s[i])) {
                    res *= 10;
                    res += s[i++] - '0';
                }
                stk_val.push(res);
            }
            //运算符
            if (i == s.length() || s[i] == '+' || s[i] == '-' || s[i] == ')') {
                while (!stk_op.empty() && stk_op.top() != '(') {
                    tmp = stk_val.top();
                    stk_val.pop();
                    if (stk_op.top() == '+') stk_val.top() += tmp;
                    else if (stk_op.top() == '-') stk_val.top() -= tmp;
                    stk_op.pop(); 
                }
                if (i == s.length()) break;//扫描到最后且运算处理完毕，例如(1)
                else if (s[i] == ')') stk_op.pop();//是本括号内的运算结束后，左括号出栈
                else stk_op.push(s[i]);//符号栈为空，例如1+1
            } else if (s[i] == '(') {
                stk_op.push(s[i]);
            }
        }
        return stk_val.top();
    }
};