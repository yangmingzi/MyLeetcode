 /*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //将链表分成两段
 //疑问第一段元素需要逆序匹配，所以使用栈结构StackList
 //stack.pop()删除栈顶元素，但不返回该元素的值
//stack.top()返回栈顶元素，但不将元素弹出栈
class Solution {
public:
    stack<ListNode*> stackList;
    void reorderList(ListNode *head) {
        if(!head || !head->next || !head->next->next)
            return;
        ListNode *slow = head, *fast = head;
        stackList.push(head);
		//将链表分为两段
        while(fast && fast->next)
        {
            slow = slow->next;
            stackList.push(slow);
            fast = fast->next->next;
        }
		//处理奇偶逻辑
        if(fast == NULL)
        {
            stackList.pop();
        }
		//除去第一段的临界元素
        stackList.pop();
		//选取第二段的第一个元素
        ListNode *p = slow->next;
		//第一段最后一元素成为新链表的最后一个元素指向null
        slow->next = NULL;
        
        while(!stackList.empty() && p!=NULL)
        {
            ListNode *stackTemp = stackList.top();
            stackList.pop();//操控第一段的元素
            ListNode *pTemp = p;
            p = p->next;//操控第二段的元素
            //更新指针
            pTemp->next = stackTemp->next;
            stackTemp->next = pTemp;
        }
    }
};

//结构比较清晰
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
    void reverseList(ListNode* &head){
        ListNode *h = new ListNode(0);
        ListNode *tmp;
        while(head!=NULL){
            tmp = head->next;
            head->next = h->next;
            h->next = head;
            head = tmp;
        }
        head = h->next;
    }
    void twistList(ListNode *&l1,ListNode *&l2){
        ListNode *p1, *p2,*tmp;
        p1 = l1;
        p2 = l2;
        while(p1!=NULL && p2 != NULL){
            tmp = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p1->next->next;
            p2 = tmp;
        }
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return ;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l2 = slow->next;
        slow->next = NULL;
        reverseList(l2);
        twistList(head,l2);
    }
};