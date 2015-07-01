//每一个点的存水量取决于min（MostHighInTheLeft,MostHighInTheRight）。
//min()所代表的高度是——瓶颈
//想不通的话就想想2,1,0,1,2中怎么处理0那一点
/*
index:  0  1  2  3  4  5  6  7  8  9  10 11

A[index]:  0  1  0  2  1  0  1  3  2  1  2  1

left[index]: 0  1  1  2  2  2  2  3  3  3  3  3

right[index]: 3  3  3  3  3  3  3  3  2  2  2  1

min[i]: 0  1  1  2  2  2  2  3  2  2  2  1

bit[i]: -  0  1  0  1  2  1  0  0  1  0  0 
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0,max,i,j;
		int len = height.size();
		if(height.size()==0 || height.size()==1)
			{return ans;}
			
		vector<int> left(len);
		vector<int> right(len); 
		
		left[0]=height[0];
		max=height[0];
		for(i=1;i<len;i++)
		{
			if(max<height[i]) { max = height[i];}
			left[i]=max;
		}
		right[len-1]=0;
		max=height[len-1];
		for(i=len-2;i>0;i--)
		{
			if(max<height[i]){max=height[i];}
			right[i]=max;
		}
		for(j=1;j<len-1;j++)
		{
			int bit,min;
			if(left[j]<right[j]){min=left[j];}
			else {min = right[j];}
			bit=min-height[j];
			if(bit>0)
				ans+=bit;
		}
		return ans;
    }
};