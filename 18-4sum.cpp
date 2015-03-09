class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int>> result;
		unordered_map<int,vector<pair<int,int>>> cache;
		if(num.size()<4) return result;
		sort(num.begin(),num.end());
		
		for(int a=0;a<num.size();++a){
			for(int b=a+1;b<num.size();++b){
				cache[num[a]+num[b]].push_back(pair<int,int>(a,b));
			}
		}
		
		for(int c=0;c<num.size();++c){
			for(int d=c+1;d<num.size();++d){
				int key = target - num[c] - num[d];
				if(cache.find(key) == cache.end()) continue;
				
				const auto& vec = cache[key];
				for(int i=0;i<vec.size();++i){
					if(c<=vec[i].second) continue;
					result.push_back({num[vec[i].first],num[vec[i].second],num[c],num[d]});
				}
			}
		}
		sort(result.begin(),result.end());
		result.erase(unique(result.begin(),result.end()),result.end());
		return result;				
    }
};

/*
class Solution {
private:
    vector<vector<int> > ret;
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        ret.clear();
        
        for(int i = 0; i < num.size(); i++)
        {
            if (i > 0 && num[i] == num[i-1])
                continue;
                
            for(int j = i + 1; j < num.size(); j++)
            {
                if (j > i + 1 && num[j] == num[j-1])
                    continue;
                    
                int k = j + 1;
                int t = num.size() - 1;
                
                while(k < t)
                {
                    if (k > j + 1 && num[k] == num[k-1])
                    {
                        k++;
                        continue;
                    }
                    
                    if (t < num.size() - 1 && num[t] == num[t+1])
                    {
                        t--;
                        continue;
                    }
                    
                    int sum = num[i] + num[j] + num[k] + num[t];
                    
                    if (sum == target)
                    {
                        vector<int> a;
                        a.push_back(num[i]);
                        a.push_back(num[j]);
                        a.push_back(num[k]);
                        a.push_back(num[t]);
                        ret.push_back(a);
                        k++;
                    }
                    else if (sum < target)
                        k++;
                    else
                        t--;                        
                }
            }
        }
        
        return ret;
    }
};*/