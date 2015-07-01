/*
本体的这种map方法非常常用
map.find()如果寻找不到就会返回尾迭代器
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mymap;
        for(int i=0;i<nums.size();i++){
        	if(mymap.find(nums[i])!=mymap.end() && i-mymap[nums[i]]<=k){
        		return true;
        	}
        	mymap[nums[i]]=i;
        }
        return false;
    }
};