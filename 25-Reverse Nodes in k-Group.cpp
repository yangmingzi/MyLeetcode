/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/
//三种解法在leetcode都时快时慢，呵呵，自己感觉第一种最好理解
/*
每次选取好一个group后,调用翻转链表子函数翻转该group
上面的方法实际上遍历了2遍链表,可以稍加改进在计数k个链表的过程中就开始翻转,
 最后部分如果不足k个节点,则还原原来的顺序   
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode tmphead(0);
        ListNode *p = head, *tail = &tmphead;//tail 为当前已经处理完的尾节点
        while(p)
        {
            pair<ListNode*, ListNode*>ht = reverseList(p,k);
            tail->next = ht.first;
            tail = ht.second;
            p = tail->next;
        }
        return tmphead.next;
    }
    //翻转从head开始的k个链表节点，如果不足k个则不翻转，返回翻转后的这k个节点
    //子链表的head和tail。翻转后的子链表还是和子链表后面的部分相连的。
    pair<ListNode*, ListNode*> reverseList(ListNode* head, int k)
    {
        ListNode *p = head, *newHead = NULL;
        int cnt = 0;
        while(p && cnt < k)
        {
            ListNode *tmp = p->next;
            p->next = newHead;
            newHead = p;
            p = tmp;
            cnt++;
        }
        head->next = p;//把翻转后的子链表和子链表后面的部分连起来
        if(cnt == k)
            return make_pair(newHead, head);
        else return reverseList(newHead, cnt);//不足k个，还原原来的顺序
    }
};

//九章算法的答案:
/*
// version 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        while (head->next != NULL) {
            head = reverseKNodes(head, k);
        }
        return dummy->next;
    }
    
    // reverse the next k nodes AFTER head: head->n1->n2..->nk->.. => head->nk->nk-1...->n1->..
    // return n1 (the next head)
    ListNode *reverseKNodes(ListNode *head, int k) {
        ListNode *node = head;
        for (int i = 0; i < k; i++) {
            if (node->next == NULL) {
                return node;
            }
            node = node->next;
        }
        
        ListNode *n1 = head->next;
        ListNode *curt = n1;
        ListNode *next = curt->next;
        for (int i = 0; i < k - 1; i++) {
            if (next == NULL) {
                n1->next = NULL;
                break;
            }
            ListNode *temp = next->next;
            next->next = curt;
            curt = next;
            next = temp;
        }
        head->next = curt;
        n1->next = next;
        return n1;
    }
};


// version 2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // p1->p1next->...->p2->p2next
    //      |____________|
    //   reverse this part to:
    // p1->p2->.......->p1next->p2next;
    // return p1next;
    ListNode *reverse(ListNode *p1, ListNode *p2) {
        ListNode *p1next = p1->next;
        ListNode *p2next = p2->next;
        ListNode *prev = p2next;
        ListNode *p = p1next; 
        
        while (p != p2next) {
            ListNode *temp = p ->next;
            p->next = prev;
            prev = p;
            p = temp;
        }
        p1->next = p2;
        return p1next;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *p1 = dummy, *p2 = dummy;
        
        for (int i = 0; i < k; i++) {
            if (p2 == NULL) {
                break;
            }
            p2 = p2->next;
        }
        if (p2 == NULL) {
            return head;
        }
        
        while (p2 != NULL) {
            p2 = reverse(p1, p2);
            for (int i = 0; i < k; i++) {
                if (p2 == NULL) {
                    break;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        return dummy->next;
    }
};
*/