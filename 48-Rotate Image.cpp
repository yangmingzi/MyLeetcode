/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
//参考博客：http://www.cnblogs.com/TenosDoIt/p/3768734.html
//先将矩阵转置，然后把转置后的矩阵每一行翻转
//可以见矩阵看成多个环组成，旋转一个矩阵，相当于把每一个环都旋转。
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        //转置
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                swap(matrix[i][j] , matrix[j][i]);
        //每一行翻转
        for(int i = 0; i < n; i++)
            for(int j = 0; j < (n>>1); j++)
                swap(matrix[i][j], matrix[i][n-j-1]);
    }
};

//先对角线翻转，在上下翻转
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if(n <= 1) return ;
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n - i; j++) {
                swap(matrix[i][j] , matrix[n-1-j][n-1-i]);
            }
        }
        
        for(int i = 0 ; i < n / 2 ; i++) {
            for(int j = 0 ; j < n ; j++) {
                swap(matrix[i][j] , matrix[n-i-1][j]);
            }
        }
    }
};