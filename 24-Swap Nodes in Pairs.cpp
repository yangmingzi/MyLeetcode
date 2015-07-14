/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
/*
/*给链表添加一个临时的头结点, 这样操作更方便。其实大部分链表问题,添加一个头结点，都会简化后面的操作*/

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
    ListNode *swapPairs(ListNode *head) {
        ListNode tmphead(0); tmphead.next = head;
        ListNode *pre = &tmphead, *p = head;
        while(p && p->next)//p 和 p->next是待交换的两个节点，pre是p的前一个节点
        {
            pre->next = p->next;
            p->next = p->next->next;
            pre->next->next = p;
             
            pre = p;
            p = p->next;
        }
        return tmphead.next;
    }
};