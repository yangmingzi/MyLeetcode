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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL)return NULL;
        //为了操作方便，添加额外的头结点tmpHead
        ListNode *tmpHead = new ListNode(0), *p = head, *mpre = tmpHead;
        tmpHead->next = head;
        for(int i = 1; i < m; i++)
        {mpre = p; p = p->next;}//找到m节点
        ListNode *pafter = p->next, *mbackup = p;
        for(int i = 1; i <= n-m; i++)
        {//反转m到n的指针
            ListNode *pre = p;
            p = pafter;
            pafter = pafter->next;
            p->next = pre;
        }
        //连接
        mbackup->next = pafter;
        mpre->next = p;
        head = tmpHead->next;
        delete tmpHead;
        return head;
    }
};