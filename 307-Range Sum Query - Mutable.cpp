/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/
//线段树
struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b):start(a),end(b),sum(0),left(nullptr),right(nullptr){}
};
class NumArray {
    SegmentTreeNode* root;
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        root = buildTree(nums,0,n-1);
    }

    void update(int i, int val) {
        modifyTree(i,val,root);
    }

    int sumRange(int i, int j) {
        return queryTree(i, j, root);
    }
    SegmentTreeNode* buildTree(vector<int> &nums, int start, int end) {
        if(start > end) return nullptr;
        SegmentTreeNode* root = new SegmentTreeNode(start,end);
        if(start == end) {
            root->sum = nums[start];
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = buildTree(nums,start,mid);
        root->right = buildTree(nums,mid+1,end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    int modifyTree(int i, int val, SegmentTreeNode* root) {
        if(root == nullptr) return 0;
        int diff;
        if(root->start == i && root->end == i) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int mid = (root->start + root->end) / 2;
        if(i > mid) {
            diff = modifyTree(i,val,root->right);
        } else {
            diff = modifyTree(i,val,root->left);
        }
        root->sum = root->sum + diff;
        return diff;
    }
    int queryTree(int i, int j, SegmentTreeNode* root) {
        if(root == nullptr) return 0;
        if(root->start == i && root->end == j) return root->sum;
        int mid = (root->start + root->end) / 2;
        if(i > mid) return queryTree(i,j,root->right);
        if(j <= mid) return queryTree(i,j,root->left);
        return queryTree(i,mid,root->left) + queryTree(mid+1,j,root->right);
    }
};

//
class NumArray {
public:
    vector<int> arr;
    vector<int> tree;
    int length;
    NumArray(vector<int> &nums) {
        length = nums.size();
        vector<int> tmp(length,0);
        arr = tmp;
        tree = tmp;
        tree.push_back(0);
        for (int i = 0; i < length; i++) {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int delta = val - arr[i];
        arr[i] = val;
        i++;
        while(i <= length) {
            tree[i] += delta;
            i += i&(-i);
        }
    }

    int sumRange(int i, int j) {
        int sumi = 0;
        int sumj = 0;
        j++;
        while (i > 0) {
            sumi += tree[i];
            i -= i &(-i);
            sumj += tree[j];
            j -= j &(-j);
        }
        while (j > 0) {
            sumj += tree[j];
            j -= j &(-j);
        }
        return sumj - sumi;
    }
};
