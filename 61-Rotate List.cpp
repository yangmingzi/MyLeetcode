/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/
/*
这里的k是指右边的节点数目，如题，k指的是4和5。

另外一个题目没有说明白的就是，若k大于链表长度该如何处理。经过多次NG，发现是将k%len。

明白这些，编码就很容易了。面试的时候一定要问清楚面试官。
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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = getListLen(head);
        if(k<=0 || len==0){
            return head;
        }
        k = k%len;
        ListNode* myHead = new ListNode(0);
        ListNode* tail = myHead;
        ListNode* p = head;
        for(int i=len-k;i>0;i--){
            tail->next = p;
            tail=tail->next;
            p=p->next;
        }
        tail->next = NULL;
        tail = myHead;
        ListNode* q;
        while(p!=NULL){
            q=p->next;
            p->next = tail->next;
            tail->next=p;
            tail=tail->next;
            p=q;
        }
        head=myHead->next;
        delete myHead;
        return head;
    }
    int getListLen(ListNode* head){
        int len = 0;
        while(head!=NULL){
            head=head->next;
            len++;
        }
        return len;
    }
};


//先成环，在断开
/*
方法：先成环，再断开链表。

思路：由于旋转的节点数k可能为0，也可能超过链表的长度，所以我们需要对k取余。
游标指针从头节点向后移动，当指向尾节点时，得到链表长度len；然后将链表头尾相连，接着游标再向后移动 k % len 步得到结果链表的尾节点。
最后将head指向结果尾部节点的下一个节点，再断开链表（尾部节点->next置NULL）
1. 由于旋转后，我们并没有改变相对节点顺序（如1-2-3-4，k=2,变为3-4-1-2），所以可以先形成链表环，之后再要求位置断开。
这种方法十分巧妙，应该学习。（此时，p指向原链表最后一个节点）
2. 需要考虑k的不同取值，k = 0, k<=len, k> len, 取余得到相对旋转位置。
3. 注意初始时，如果链表无节点，返回head, 排除特殊情况。
复杂度：O(N)
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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL) return head;
        ListNode* p = head;
        int len = 1;
        //(1) 计算链表长度
        while(p->next != NULL)
        {
            p = p->next;
            len++;
        }
        
        //(2) 让链表头尾相连
        p->next = head;
        
        //(3) 找到结果链表的尾节点
        k %= len;
        int step = len - k;
        while(step > 0)
        {
            p = p->next;
            step--;
        }
        
        //(4) 断开链表，从结果链表的尾节点位置 新的头结点，是结果链表尾节点的下一个结点。结果链表尾节点->next 置NULL
        head = p->next;
        p->next = NULL;
        
        return head;
    }
};