/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.
*/
/*
因此只需要判断9*9网格的每一行、每一列、9个小九宫格是否合法。
即如果在每一行、每一列、每个9个小九宫格内，某个数字重复出现了，当前数独就是不合法的。  
这种类型的游戏一般回溯法来解决，设置某个空格时，如果该空格无论设置什么数字都无法达到合法状态，那么回溯重新设置上一个空格，详细见代码注释
*/
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(board[i][j] != '.')
                    fill(i, j, board[i][j] - '0');
        solver(board, 0);
    }
     
    bool solver(vector<vector<char> > &board, int index)
    {// 0 <= index <= 80，index表示接下来要填充第index个格子
        if(index > 80)return true;
        int row = index / 9, col = index - 9*row;
        if(board[row][col] != '.')
            return solver(board, index+1);
        for(int val = '1'; val <= '9'; val++)//每个为填充的格子有9种可能的填充数字
        {
            if(isValid(row, col, val-'0'))
            {
                board[row][col] = val;
                fill(row, col, val-'0');
                if(solver(board, index+1))return true;
                clear(row, col, val-'0');
            }
        }
        board[row][col] = '.';//注意别忘了恢复board状态
        return false;
    }
     
    //判断在第row行col列填充数字val后，是否是合法的状态
    bool isValid(int row, int col, int val)
    {
        if(rowValid[row][val] == 0 &&
           columnValid[col][val] == 0 &&
           subBoardValid[row/3*3+col/3][val] == 0)
           return true;
        return false;
    }
     
    //更新填充状态
    void fill(int row, int col, int val)
    {
        rowValid[row][val] = 1;
        columnValid[col][val] = 1;
        subBoardValid[row/3*3+col/3][val] = 1;
    }
     
    //清除填充状态
    void clear(int row, int col, int val)
    {
        rowValid[row][val] = 0;
        columnValid[col][val] = 0;
        subBoardValid[row/3*3+col/3][val] = 0;
    }
private:
    int rowValid[9][10];//rowValid[i][j]表示第i行数字j是否已经使用
    int columnValid[9][10];//columnValid[i][j]表示第i列数字j是否已经使用
    int subBoardValid[9][10];//subBoardValid[i][j]表示第i个小格子内数字j是否已经使用
};