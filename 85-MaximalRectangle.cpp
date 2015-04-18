//也可以参考一下下面链接里的方法，挺有趣的
//http://blog.csdn.net/hopeztm/article/details/7870387

class Solution {
//for each element in matrix, we compute h[j](current consecutive length of '1'), L[j] (nearest left wall whose height is smaller than current column), and R[j] (nearest right wall whose height is smaller than current column) for it, update these three terms row by row
//here we compute the most far range(both in height, and width) of scan line j at every row i
//to get the size of the rectangle of f[i][j]. To achieve this, we should compute:
//H[j](the maximum bottom up height of current column until meet the first '0')
//L[j](the most far position where can the scan line j can go at the left)
//R[j](the most far position where can the scan line j can go at the right)
//then f[i][j]=H[j]*(R[j]-L[j]+1), ans=max(ans,f[i][j])
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int ans = 0;
		if(matrix.size() == 0) return ans;
		int m = matrix[0].size();
		vector<int>L(m, -1);
		vector<int>R(m, m);
		vector<int>H(m, 0);
		for (int i = 0; i < matrix.size(); ++i)
		{
			//scan from left to right to update H and L
			int nearestLeft = -1;//virtual '0' at most far of right
			for (int j = 0; j < matrix[i].size(); ++j)
			{
				L[j] = max(nearestLeft, L[j]);
				if (matrix[i][j] == '1')
					H[j]++;
				else
				{
					H[j] = 0;
					L[j] = -1;//note here
					nearestLeft = j;
				}
			}
			//scan from right to left to update R and calculate f[i][j]
			int nearestRight = m;//virtual '0' at most far of left
			for (int j = matrix[i].size()-1; j >= 0; --j)
			{
				R[j] = min(nearestRight, R[j]);
				if (matrix[i][j] == '0')
				{
					nearestRight = j;
					R[j] = m;//note here
				}
				//calculate f[i][j]
				ans = max( ans, H[j]*(R[j]-L[j]-1) );
			}
			
		}
		return ans;
	}
};