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