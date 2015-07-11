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
    ListNode *deleteDuplicates(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL)return head;
        //为操作方便添加头结点
        ListNode *addHead = new ListNode(0);
        addHead->next = head;
        //index 指向已经保存的最后一个节点
        ListNode *index = addHead, *p = head;
        while(p != NULL)
        {
            if(p->next == NULL || p->val != p->next->val)
            {//当前节点没有重复
                index = index->next;
                index->val = p->val;
                p = p->next;
            }
            else
            {//当前节点有重复，找到当前节点的最后一个副本的下一个元素
                while(p->next && p->val == p->next->val)
                    p = p->next;
                p = p->next;
            }
        }
        p = index->next;
        index->next = NULL;
        while(p != NULL)
        {//销毁多余的节点
            ListNode *tmp = p;
            p = p->next;
            delete tmp;
        }
        head = addHead->next;
        delete addHead;
        return head;
    }
};