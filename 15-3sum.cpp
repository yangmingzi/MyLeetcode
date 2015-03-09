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

