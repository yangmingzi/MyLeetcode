//经典题目，参考博客：http://www.cnblogs.com/TenosDoIt/p/3465240.html
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
    ListNode *deleteDuplicates(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL || head->next == NULL)return head;
        ListNode *index = head, *p = head->next, *pre = head;
        while(p != NULL)
        {
            if(p->val != pre->val)
            {
                index = index->next;
                index->val = p->val;
            }
            pre = p;
            p = p->next;
        }
        p = index->next;
        index->next = NULL;
        while(p != NULL)
        {//销毁多余的节点
            ListNode *tmp = p;
            p = p->next;
            delete tmp;
        }
        return head;
    }
};

//二刷，自己写的，速度前列
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* pre = head;
        ListNode* p = head->next;
        while(p){
            if(p->val == pre->val){
                ListNode* tmp = p->next;
                pre->next = tmp;
                p = pre->next;
            }else{
                p = p->next;
                pre = pre->next;
            }
        }
        return head;
    }
};