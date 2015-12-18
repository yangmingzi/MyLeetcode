/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/
//http://bookshadow.com/weblog/2015/12/06/leetcode-count-of-smaller-numbers-after-self/
//
class BSTNode{
    public:
    int count, val;
    BSTNode *left, *right;
    BSTNode(int value, int cnt) {
        val = value; 
        count = cnt;  // count is the # of nodes of the subtree rooted at this node.
        left=right=nullptr;
    }
};

class Solution {
private: 
    int insertNum(BSTNode *root, int num, int cnt){ //cnt is the number of nodes that have less than num values from layers higher than root
        ++(root->count); // increase root node counter
        if(root->val == num)  // if root has value of num, then the number of nodes less than num is cnt + number of nodes of its left subtree 
            return cnt + (root->left!=nullptr? root->left->count:0);  
        else if(root->val > num) 
        { // goes into the left subtree, do recursiion
            if(!root->left) root->left = new BSTNode(num,0); 
            return insertNum(root->left, num, cnt);
        }
        else 
        { // goes into the right-subtree, update cnt as cnt + the number of nodes of its left subtree + the number of nodes with value of root->val
            if(!root->right) root->right = new BSTNode(num,0); 
            return insertNum(root->right, num, cnt+root->count-root->right->count-1);
        }
    }
    void deleteTree(BSTNode *root)
    {//recursive destroy the tree
        if(root)
        {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int i, nSize = nums.size();
        vector<int> res(nSize,0);
        if(nSize>1)
        {
            BSTNode *root = new BSTNode(nums[nSize-1], 1);
            for(i = nSize-2; i>=0; --i) res[i] = insertNum(root, nums[i], 0);
            deleteTree(root);
        }
        return res;    
    }
};

//
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret, clone = nums;;
        int len = (int) nums.size();
        unordered_map<int, int> reflect;
        array.resize(len + 1);
        sort(clone.begin(), clone.end());
        for (int i = 0; i < len; ++ i)
            reflect[clone[i]] = i + 1;

        for (int i = len - 1; i >= 0; -- i) {
            clone[i] = query(reflect[nums[i]] - 1);
            add(reflect[nums[i]], 1);
        }
        return clone;
    }

private:
    vector<int> array;
    inline int lowbit(int pos) {
        return pos & -pos;
    }
    void add(int pos, int val) {
        long len = array.size();
        while (pos < len) {
            array[pos] += val;
            pos += lowbit(pos);
        }
    }
    int query(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += array[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
};