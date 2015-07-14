/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
/*
维护一个k个大小的最小堆，初始化堆中元素为每个链表的头结点，
每次从堆中选择最小的元素加入到结果链表，
再选择该最小元素所在链表的下一个节点加入到堆中。
这样当堆为空时，所有链表的节点都已经加入了结果链表。
元素加入堆中的复杂度为O（longk），
总共有kn个元素加入堆中，因此，复杂度也和算法2一样是O（nklogk）
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
private:
struct cmp
{
    bool operator ()(const ListNode *a, const ListNode *b)
    {
            return a->val > b->val;
    }
};
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if(n == 0)return NULL;
        ListNode node(0), *res = &node;
        priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        for(int i = 0; i < n; i++)
            if(lists[i])
                que.push(lists[i]);
        while(!que.empty())
        {
            ListNode * p = que.top();
            que.pop();
            res->next = p;
            res = p;
             
            if(p->next)
                que.push(p->next);
        }
        return node.next;
    }
};
/*
利用分治的思想把合并k个链表分成两个合并k/2个链表的任务，
一直划分，知道任务中只剩一个链表或者两个链表。
可以很简单的用递归来实现。
因此算法复杂度为T(k) = 2T(k/2) + O(nk),很简单可以推导得到算法复杂度为O（nklogk）

递归的代码就不贴了。下面是非递归的代码非递归的思想是（以四个链表为例）：              

1、3合并，合并结果放到1的位置

2、4合并，合并结果放到2的位置

再把1、2合并（相当于原来的13 和 24合并）
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if(n == 0)return NULL;
        while(n >1)
        {
            int k = (n+1)/2;
            for(int i = 0; i < n/2; i++)
                lists[i] = merge2list(lists[i], lists[i + k]);
            n = k;
        }
        return lists[0];
    }
     
    ListNode *merge2list(ListNode *head1, ListNode*head2)
    {
        ListNode node(0), *res = &node;
        while(head1 && head2)
        {
            if(head1->val <= head2->val)
            {
                res->next = head1;
                head1 = head1->next;
            }
            else
            {
                res->next = head2;
                head2 = head2->next;
            }
            res = res->next;
        }
        if(head1)
            res->next = head1;
        else if(head2)
            res->next = head2;
        return node.next;
    }
};
/*
超时超到死的做法
最傻的做法就是先1、2合并，12结果和3合并，123结果和4合并，…,123..k-1结果和k合并，我们计算一下复杂度。

1、2合并，遍历2n个节点

12结果和3合并，遍历3n个节点

123结果和4合并，遍历4n个节点

…

123..k-1结果和k合并，遍历kn个节点

总共遍历的节点数目为n(2+3+…+k) = n*(k^2+k-2)/2, 因此时间复杂度是O(n*(k^2+k-2)/2) = O(nk^2)，代码如下：
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0)return NULL;
        ListNode*res = lists[0];
        for(int i = 1; i < lists.size(); i++)
            res = merge2list(res, lists[i]);
        return res;
    }
     
    ListNode *merge2list(ListNode *head1, ListNode*head2)
    {
        ListNode node(0), *res = &node;
        while(head1 && head2)
        {
            if(head1->val <= head2->val)
            {
                res->next = head1;
                head1 = head1->next;
            }
            else
            {
                res->next = head2;
                head2 = head2->next;
            }
            res = res->next;
        }
       if(head1)
            res->next = head1;
        else if(head2)
            res->next = head2;
        return node.next;
    }
};