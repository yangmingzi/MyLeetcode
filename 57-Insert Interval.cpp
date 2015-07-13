/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/
/*
在原始数组上操作，先按照start值在原数组中二分查找待插入的区间，
假设查找到的位置为ite，从ite或者ite-1开始合并区间直到不能合并为止（终止条件是合并后区间的end<当前区间的start）
然后在原数组中删除参与合并的区间，再插入合并后的新区
*/
class Solution {
private:
    static bool comp(Interval a, Interval b)
    {
        return a.start < b.start;
    }
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        //在原始数组上操作
        vector<Interval>::iterator ite = lower_bound(intervals.begin(),intervals.end(), newInterval, comp);//按照start值二分查找
        if(ite != intervals.begin() && newInterval.start <= (ite-1)->end)//ite的上一个区间也可能参与合并
        {
            ite--;
            //合并后新区间的起点只和第一个合并的区间有关，因为数组时按区间起点有序的
            newInterval.start = min(newInterval.start, ite->start);
        }
        vector<Interval>::iterator eraseBegin = ite;
        for(; ite != intervals.end() && newInterval.end >= ite->start; ite++)
            if(newInterval.end < ite->end)newInterval.end = ite->end;//合并后的新区间存放于newInterval
         
        ite = intervals.erase(eraseBegin, ite);//[eraseBegin, ite)是合并时应该删掉的区间
        intervals.insert(ite, newInterval);//插入合并后的区间
        return intervals;
    }
};