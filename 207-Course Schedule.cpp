//拓扑排序（效率略低，352ms，需要寻找更高效解法，书影博客中的python解法可进入200ms）
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
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
               return false;
            }
            //删除j
            into[j] = -1;          
            //删除和j有关系的节点和j的关系
            for(int p = 0; p < prerequisites.size(); ++p)
                if(prerequisites[p].second == j)
                    into[prerequisites[p].first]--;
        }
      
        for(int i=0;i<into.size();i++)
        {
            if(into[i]!=-1)return false;
        }
        return true;
    }
};