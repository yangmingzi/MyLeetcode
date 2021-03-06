//用插入排序的方法排序链表
//引入一个新的节点当做伪头部
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
    ListNode *insertionSortList(ListNode *head) {
         if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *h = new ListNode(0);
    h->next = head;
    ListNode *p, *q, *tmp;
    bool flag;
    for (p = head; p->next != NULL;) {
        flag = false;
        for (q = h; q != p; q = q->next) {
            if (p->next->val < q->next->val) {
                tmp = p->next;
                p->next = tmp->next;
                tmp->next = q->next;
                q->next = tmp;
                flag = true; break;
            }
        }
        if (!flag) p = p->next;
    }
    head = h->next;
    delete h; h = NULL;
    return head;
    }
};
//新的链表以helper->next为开始，遍历原始链表(cur)并且记录(tmp)，插入新的链表(pre)，
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    { 
        if(head==NULL || head->next==NULL) return head;
        ListNode *cur=head;
        ListNode *helper=new ListNode(0);
        ListNode *pre;
        while(cur)
        {
            ListNode *next=cur->next;
            pre=helper;
            while(pre->next!=NULL && pre->next->val<cur->val)
            {
                pre=pre->next;
            }
            cur->next=pre->next;
            pre->next=cur;
            cur=next;
        }
        return helper->next;
    }
 
} ;