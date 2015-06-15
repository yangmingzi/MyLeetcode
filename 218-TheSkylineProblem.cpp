/*
见链接：http://www.cnblogs.com/easonliu/p/4531020.html
分别将每个线段的左边节点与右边节点存到新的vector height中，根据x坐标值排序，然后遍历求拐点。
求拐点的时候用一个最大化heap来保存当前的楼顶高度，
遇到左边节点，就在heap中插入高度信息，遇到右边节点就从heap中删除高度。
分别用pre与cur来表示之前的高度与当前的高度，当cur != pre的时候说明出现了拐点。
在从heap中删除元素时要注意，我使用priority_queue来实现，priority_queue并不提供删除的操作，
所以又用了别外一个unordered_map来标记要删除的元素。
multiset提供了删除操作，而且multiset内的数据也是按堆排好序的。
在从heap中pop的时候先看有没有被标记过，如果标记过，就一直pop直到空或都找到没被标记过的值。
别外在排序的时候要注意，如果两个节点的x坐标相同，我们就要考虑节点的其它属性来排序以避免出现冗余的答案。
且体的规则就是如果都是左节点，就按y坐标从大到小排，如果都是右节点，按y坐标从小到大排，
一个左节点一个右节点，就让左节点在前。下面是AC的代码。
*/
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > h, res;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto &a : buildings) {
            h.push_back({a[0], -a[2]});
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());
        m.insert(0);
        for (auto &a : h) {
            if (a.second < 0) m.insert(-a.second);
            else m.erase(m.find(a.second));
            cur = *m.rbegin();
            if (cur != pre) {
                res.push_back({a.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};