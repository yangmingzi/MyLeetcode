/*
lower_bound()返回一个 iterator 它指向在[first,last)标记的有序序列中可以插入value，而不会破坏容器顺序的第一个位置，
而这个位置标记了一个不小于value 的值。
*/


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> s;

        for(int i=0;i<nums.size();i++){
        	if(s.size()==k+1){
        		s.erase(s.find(nums[i-(k+1)]));
        	}
        	auto it = s.lower_bound(nums[i]-t);//因为muliiset默认的顺序是由小到大，所以此处nums[i]-t
        	if(s.find(*it)!=s.end()){
        		int diff = nums[i]>*it ? nums[i]-*it:*it-nums[i];
        		if(diff<=t)
        		{
        			return true;
        		}
        	}
        	s.insert(nums[i]);
        }
        return false;
    }
};