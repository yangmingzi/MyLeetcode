/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
		result.clear();
		if(num.size()<3) return result;
		sort(num.begin(),num.end());
		
		for(int a=0;a<num.size();++a){
			//a变化时检查，去重
			if(a>0 && num[a]==num[a-1])
				continue;
			int b=a+1;			
			int c=num.size()-1;						
			while(b<c){	
				//b>a+1是为了处理在a确定的情况下的内部循环，去重
				if(b>a+1&&num[b]==num[b-1]) {++b;continue;}
				if(c<num.size()-1&&num[c]==num[c+1]) {--c;continue;}		
				int sum=num[a]+num[b]+num[c];
				if(sum>0){
					--c;
				}else if(sum<0){
					++b;
				} 
				/*************************************************
				在相等的情况下，也不要忘记处理循环变量的下一次变化
				此处是不可忘记--c！
				切记！！！
				**************************************************/				   
				else {
					//两种写法耗费内存一样
					/*
					vector<int> tmp;
					tmp.push_back(num[a]);
					tmp.push_back(num[b]);
					tmp.push_back(num[c]);
					result.push_back(tmp);
					*/
					result.push_back({num[a],num[b],num[c]});
					--c;				
				}				
			}
		}
	return result;
    }
};
//
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            while(i > 0 && i < n && nums[i] == nums[i-1])
                i ++;
            int j = i+1;
            int k = n-1;
         while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    vector<int> tmp(3);
                    tmp[0] = nums[i];
                    tmp[1] = nums[j];
                    tmp[2] = nums[k];
                    res.push_back(tmp);
                    j++;
                    k--;
                    while(j<k&&nums[j]==nums[j-1]){
                        j++;
                    }
                    while(k>j && nums[k] == nums[k+1]){
                        k--;
                    }
                }
                //下面两个判断中的while去重可以不加，但是加上可以提高效率
                else if(sum<0){
                     j++;
                    //  while(j<k&&nums[j]==nums[j-1]){
                    //     j++;
                    // }
                }
                else{
                    k--;
                    // while(k>j && nums[k] == nums[k+1]){
                    //     k--;
                    // }
                }
            }
        }
        return res;
    }
};

