// /八皇后问题
//DFS+回溯
//isvalid函数极其琐碎，需多多练习
 /*为什么不能写成
        for(int i=0;i<=row;i++){if(cur[i][col]=='Q') return false;}
        for(int i=0,j=0;i<=row&&j<=col;i++,j++){if(cur[i][j]=='Q') return false;}
        for(int i=row,j=col;i>=0&&j<cur.size();i--,j++){if(cur[i][j]='Q') return false;}
*/
class Solution {
private:
    vector<vector<string> > res;
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<string>cur(n, string(n,'.'));//别写成 vector<string>cur=(n,string(n,'.'))
        helper(cur, 0);
        return res;
    }
    void helper(vector<string> &cur, int row)
    {
        if(row == cur.size())
        {
            res.push_back(cur);
            return;
        }
        for(int col = 0; col < cur.size(); col++)
            if(isValid(cur, row, col))
            {
                cur[row][col] = 'Q';
                helper(cur, row+1);
                cur[row][col] = '.';
            }
    }
     
    //判断在cur[row][col]位置放一个皇后，是否是合法的状态
    //已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法。
    bool isValid(vector<string> &cur, int row, int col)
    {
        //列
        for(int i = 0; i < row; i++)
            if(cur[i][col] == 'Q')return false;
        //右对角线(只需要判断对角线上半部分，因为后面的行还没有开始放置)

        for(int i = row-1, j=col-1; i >= 0 && j >= 0; i--,j--)
            if(cur[i][j] == 'Q')return false;
        //左对角线(只需要判断对角线上半部分，因为后面的行还没有开始放置)
        for(int i = row-1, j=col+1; i >= 0 && j < cur.size(); i--,j++)
            if(cur[i][j] == 'Q')return false;
        return true;
    }
};


