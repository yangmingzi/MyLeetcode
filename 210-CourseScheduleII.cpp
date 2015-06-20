//拓扑排序
class Solution {
public:
   vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        vector<int> into(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); ++i)
            into[prerequisites[i].first]++;
        for(int i = 0; i < numCourses; ++i){
            int j = 0;
            //找到没有前驱的顶点
            while(j < numCourses){
                if(into[j] == 0)
                    break;
                ++j;
            }
            //如果没找到，则证明是环，得不到想要的结果
            if(j == numCourses){
                result.clear();
                return result;
            }
            //删除j
            into[j] = -1;
            result.push_back(j);
            //删除和j有关系的节点和j的关系
            for(int p = 0; p < prerequisites.size(); ++p)
                if(prerequisites[p].second == j)
                    into[prerequisites[p].first]--;
        }
        return result;
    }
};