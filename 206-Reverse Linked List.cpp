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
    ListNode* reverseList(ListNode* head) {
        ListNode* resultHead=new ListNode(0);//辅助结点,为什么要new?
        ListNode* p=head, *q;
        
        while(p!=NULL){
            q=p->next;//推进一步，准备记录新的P
            p->next=resultHead->next;
            resultHead->next=p;
            p=q;
        }
        
        p=resultHead;
        resultHead=resultHead->next;//设置新的头结点
        delete p;//释放辅助结点
        return resultHead;
    }
};