/*
层次遍历，去每层最右侧的节点
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* curr;
        while(!que.empty()) {
            int cnt = que.size();
            for (int i = 0; i < cnt; i++) {
                curr = que.front(); que.pop();
                if (curr->left) {
                    que.push(curr->left);
                }
                if (curr->right) {
                    que.push(curr->right);
                }
            }
            ans.push_back(curr->val);
        }
        return ans;
    }
};