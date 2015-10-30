/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/
//复制一棵树
//深搜广搜都可以实现
//80ms,34.12
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

//76ms,60.16%
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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        unordered_map<UndirectedGraphNode* ,UndirectedGraphNode*>nodeMap;
        queue<UndirectedGraphNode*> visit;
        visit.push(node);
        UndirectedGraphNode* nodeCopy = new UndirectedGraphNode(node->label);
        nodeMap[node] = nodeCopy;
        while(visit.size()>0){
            UndirectedGraphNode* cur = visit.front();
            visit.pop();
            for(int i=0;i<cur->neighbors.size();i++){
                UndirectedGraphNode* neighb = cur->neighbors[i];
                if(nodeMap.find(neighb) == nodeMap.end()){
                    UndirectedGraphNode* neighCopy = new UndirectedGraphNode(neighb->label);
                    nodeMap[cur]->neighbors.push_back(neighCopy);
                    nodeMap[neighb] = neighCopy;
                    visit.push(neighb);
                }else{
                    nodeMap[cur]->neighbors.push_back(nodeMap[neighb]);
                }
            }
        }
        return nodeCopy;
    }
};