class Solution {
public:
     int majorityElement(vector<int> &num) {
       unordered_map<int,int>  map;
       for(int i=0;i<num.size();i++){
           if(map.find(num[i])==map.end()) map[num[i]]==0;
           else{map[num[i]]++;}
           
           if(map[num[i]]>=num.size()/2) return num[i];
       }
      
    }
};