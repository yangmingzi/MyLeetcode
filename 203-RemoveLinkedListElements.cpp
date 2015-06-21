//设删除的节点为q，q不是头结点的时候，则为了完成目标，我们需要他前后节点的信息即q->front和q->back
//因为没有q->front，所以设节点p，p->next = q->next
//因此我们必须从第二个节点开始遍历
//因为特例情况，不能上来就检查头结点
//特殊情况：1.头结点需要删除2.最后需要删除头结点
//都会进入到next==NULL的步骤
//注意：节点NULL没有next
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;   
        ListNode *cur = head, *next = head->next;
        while (next != NULL) {// 当存在大于一个节点时
            if (next->val == val) {
                cur->next = next->next;
                delete next;
                next = cur->next;
            } else {
                cur = cur->next;
                next = next->next;
            }
        }
        if (head->val == val) {//特例：[1,1],1
            cur = head;
            head = head->next;
            delete cur;
        }
        return head;
    }
};