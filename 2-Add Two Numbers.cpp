/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 大整数加法
 注意：链表中，整数的低位在前  
参考博客：http://www.cnblogs.com/TenosDoIt/p/3735362.html
里面讲述了如果链表存储整数时，高位在前，该如何处理
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carryBit = 0;
        ListNode tmpHead(0), *res = &tmpHead;
        while(l1 && l2)
        {
            l1->val += (l2->val + carryBit);
            carryBit = l1->val / 10;
            l1->val %= 10;
            res->next = l1;
            res = l1;
             
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *p = (l1 == NULL ? l2 : l1); //此时l1,l2至多一个不为NULL
        while(p)
        {
            if(carryBit == 0)
            {
                res->next = p;
                break;
            }
            else
            {
                p->val += carryBit;
                carryBit = p->val / 10;
                p->val %= 10;
                res->next = p;
                res = p;
            }
            p = p->next;
        }
        if(carryBit != 0)res->next = new ListNode(carryBit);
         
        return tmpHead.next;
    }
};
//二刷，和一刷的方法、速度都一样，36ms,48.35%，代码稍稍精简了一些
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* tmp = new ListNode(0);
        ListNode *res = tmp;
        while(l1 && l2){
            l1->val += (l2->val+carry);
            carry = l1->val/10;
            l1->val = l1->val%10;
            res->next = l1;
            res = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* noEm = (l1==NULL?l2:l1);
        while(noEm){
            noEm->val = noEm->val + carry;
            carry = noEm->val/10;
            noEm->val = noEm->val%10;
            res->next = noEm;
            res = noEm;
            noEm = noEm->next;
        }
        if(carry!=0){
            res->next = new ListNode(carry);
        }
        return tmp->next;
    }
};
