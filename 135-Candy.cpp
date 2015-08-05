/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/
//贪心算法
//先让从左到右满足条件
//再不改变从左到右的成果的前提下，是从右到左满足条件
//局部最优到全局最优
class Solution {
public:
    int candy(vector<int> &ratings) {
		
		int len = ratings.size();
		vector<int> candy(len,1);
		int sum=0;
	    /*
		for(int i=0;i<len;++i){
			candy[i]=1;
		}
		*/
		//for循环，到数组倒数第二位截止，包括倒数第二位时，i<=len-2
		for(int i=0;i<=len-2;++i){	
			if(ratings[i]<ratings[i+1]){
				candy[i+1]=candy[i]+1;
			}
		}
		
		for(int i=len-2;i>=0;--i){
			if(ratings[i]>ratings[i+1]){
				//注意此处为candy[i+1]+1，为了不改变从左到右的结果
				candy[i]=max(candy[i],candy[i+1]+1);
			}
		}
		for(int i=0;i<len;++i){
			sum+=candy[i];
		}
		return sum;
    }
};