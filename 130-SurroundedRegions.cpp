/*
思路：目标是要找到由X包围起来的O的区域。
首先，外围一圈上的O肯定会保留下来。然后，从外围的O能达到的O也要保留。剩下其他的O就是内部的O。
所以方法就是从外围的一圈进行DFS算法：依次对外圈的“O”做DFS，将其可以到达O临时设置为#。
最后：将'O'变为'X'，将'#'恢复回'O'  
特殊用例：只有外围轮廓没有内部。比如长或者宽小于2，此时不存在被包围的'X'。

先将所有外围的‘O’标记为‘.’，再将内部的‘O’标记成‘X’并且恢复外围的‘.’为‘O’。
注意DFS时最外面的一圈已经在最开始处理过了，所以DFS时无需再进入了，否则会报内存错误。
*/

class Solution {
public:
    void fill(vector<vector<char> > &board, int x, int y) {
        board[x][y] = '.';
        if (y + 1 < board[0].size() - 1 && board[x][y+1] == 'O')
            fill(board, x, y + 1); //right
        if (x + 1 < board.size() - 1 && board[x+1][y] == 'O')
            fill(board, x + 1, y); //down
        if (y - 1 > 0 && board[x][y-1] == 'O')
            fill(board, x, y - 1); //left
        if (x - 1 > 0 && board[x-1][y] == 'O')
            fill(board, x - 1, y); //up
    }
    
    void solve(vector<vector<char>> &board) {
        if (board.size() < 3) return;
        if (board[0].size() < 3) return;
        
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][0] == 'O')
                fill(board, i, 0);
            if (board[i][board[0].size()-1] == 'O')
                fill(board, i, board[0].size() - 1);
        }
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[0][j] == 'O')
                fill(board, 0, j);
            if (board[board.size()-1][j] == 'O')
                fill(board, board.size() - 1, j);
        }
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};