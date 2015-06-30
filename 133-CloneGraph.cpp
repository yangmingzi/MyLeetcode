//复制一棵树
//深搜广搜都可以实现

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    void cloneNode(UndirectedGraphNode *&res, 
        UndirectedGraphNode *node, 
        map<int, UndirectedGraphNode*> &mp) {
        //因为是无向图，所以当检查到重复节点的时候，就结束了
        if (mp[node->label] != NULL) {
            res = mp[node->label];
            return;
        }
        res = new UndirectedGraphNode(node->label);
        res->neighbors.resize(node->neighbors.size());
        mp[node->label] = res;

        for (int i = 0; i < node->neighbors.size(); ++i) {
            cloneNode(res->neighbors[i], 
                node->neighbors[i], mp);
        }
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        map<int, UndirectedGraphNode*> mp;
        UndirectedGraphNode* res; 
        cloneNode(res, node, mp);
        return res;
    }
};