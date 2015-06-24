//八皇后问题的另外一种思路
//可以用二进制的思想去理解，一行上只能放一个皇后，要么为-1，要么为col值、
//一定要好好参考这篇博客：http://www.cnblogs.com/TenosDoIt/p/3801621.html
class Solution {
private:
    int res;
public:
    int totalNQueens(int n) {
        vector<int> state(n, -1);
        res = 0;
        helper(state, 0);
        return res;
    }
    void helper(vector<int> &state, int row)
    {//放置第row行的皇后
        int n = state.size();
        if(row == n)
        {
            res++;
            return;
        }
        for(int col = 0; col < n; col++)
            if(isValid(state, row, col))
            {
                state[row] = col;
                helper(state, row+1);
                state[row] = -1;;
            }
    }
     
    //判断在row行col列位置放一个皇后，是否是合法的状态
    //已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法。
    //如果(x1,y1)与在一条对角线上，则abs(x1-x2)==abs(y1-y2)
    bool isValid(vector<int> &state, int row, int col)
    {
        for(int i = 0; i < row; i++)//只需要判断row前面的行，因为后面的行还没有放置
            if(state[i] == col || abs(row - i) == abs(col - state[i]))
                return false;
        return true;//此句在for循环外部
    }
 
};