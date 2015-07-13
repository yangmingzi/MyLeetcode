/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
/*
对若干个区间进行合并，使合并后的区间没有重叠

先对区间按照左边界排序，然后顺序扫描，合并重叠的区间即可。

代码1在原区间数组上操作，不使用额外的空间，但是需要删除多余的区间，这样会移动数组元素
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    static bool comp(Interval a, Interval b)
    {
        return a.start < b.start;
    }
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.empty())return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval>::iterator it1 = intervals.begin(), it2 = it1 + 1;
        while(it1 != intervals.end() && it2 != intervals.end())
        {
            if(it2->start <= it1->end)
            {
                if(it1->end < it2->end)it1->end = it2->end;
                it2++;
            }
            else
            {
                //[it1+1, it2)范围内的区间可以从原数组删除
                it1 = intervals.erase(it1+1, it2);
                it2 = it1 + 1;
            }
        }
        if(it1 != intervals.end())
            intervals.erase(it1 + 1, it2);
        return intervals;
    }
};