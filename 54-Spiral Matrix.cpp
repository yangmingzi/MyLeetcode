/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
/*
打印螺旋矩阵

逐个环的打印, 对于m *n的矩阵,环的个数是 (min(n,m)+1) / 2。对于每个环顺时针打印四条边。

注意的是：最后一个环可能只包含一行或者一列数据
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int m = matrix.size(), n;
        if(m != 0)n = matrix[0].size();
        int cycle = m > n ? (n+1)/2 : (m+1)/2;//环的数目
        vector<int>res;
         
        int a = n, b = m;//a,b分别为当前环的宽度、高度
        for(int i = 0; i < cycle; i++, a -= 2, b -= 2)
        {
            //每个环的左上角起点是matrix[i][i],下面顺时针依次打印环的四条边
            for(int column = i; column < i+a; column++)
                res.push_back(matrix[i][column]);
            for(int row = i+1; row < i+b; row++)
                res.push_back(matrix[row][i+a-1]);
            if(a == 1 || b == 1)break; //最后一个环只有一行或者一列
            for(int column = i+a-2; column >= i; column--)
                res.push_back(matrix[i+b-1][column]);
            for(int row = i+b-2; row > i; row--)
                res.push_back(matrix[row][i]);
        }
        return res;
    }
};