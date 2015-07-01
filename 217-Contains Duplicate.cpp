/*
set不允许有重复元素
set.insert(A).second()检测是否插入成功，如果成功则返回true，失败则选择false
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
        	if(s.insert(nums[i]).second == false){
        		return true;
        	}
        }
        return false;
    }
};