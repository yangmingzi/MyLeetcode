class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
       vector<int> result;
       unordered_map<int ,int>  map;
       for(int i=0;i<numbers.size();++i){
           map[numbers[i]]=i;
       }
       for(int i=0;i<numbers.size();++i){
           const int  anthor = target - numbers[i];
           if(map.find(anthor)!=map.end() && map[anthor]>i){
               result.push_back(i+1);
               result.push_back(map[anthor]+1);
               break;
           }
       }
       return result;
    }
};