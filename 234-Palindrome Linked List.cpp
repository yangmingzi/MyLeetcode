/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
本题的思路其实并不难，
但是我一直觉得直接手写一个iterative版本的reverse linked list还是有一点难度的，挺难一次写通过的。
感觉这题应该算是easy里面的难题或者是medium里面简单或者中等的水平。。

算法很简单：
1，找到linkedlist的中点，
2，翻转左边的linkedlist或者右边的linkedlist均可，我是选择翻转右边的
3，然后比较
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr or head->next == nullptr) {
            return true;
        }
        ListNode* tmp = head;
        int cnt = 0;
        while (tmp != nullptr) {
            tmp = tmp->next;
            ++cnt;
        }
        ListNode* prev;
        tmp = head;
        for (int i = 0; i < cnt / 2; ++i) {
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = nullptr;
        
        // reverse the linkedlist
        if (tmp->next != nullptr) {
            ListNode* cur = new ListNode(0);
            ListNode* after = tmp->next;
            cur->next = after;
            tmp->next = nullptr;
            while (after != nullptr) {
                after = after->next;
                cur->next->next = tmp;
                tmp = cur->next;
                cur->next = after;
            }
        }
        
        // compare these two linked list
        while (head != nullptr) {
            if (tmp->val != head->val) {
                return false;
            }
            tmp = tmp->next;
            head = head->next;
        }
        return true;
    }
};

//二刷
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *p = head;
	    ListNode *q = head;
	    while (p && p->next)
	    {
		    p  = p->next->next;
		    q  = q->next;
	    }
	    q = revert(q);
	    //下面的判断是为了确定链表节点的数量的奇偶,可写可不写
	    // if(p){
	    //     q->next = revert(q->next);
	    //     q = q->next;
	    // }else{
	    //     q = revert(q);
	    // }
	    while(q){
	        if(head->val != q->val){
	            return false;
	        }
	        head = head->next;
	        q = q->next;
	    }
	    return true; 
    }
private:
    ListNode* revert(ListNode *head)
    {
	    ListNode *p = head->next;
	    ListNode *q = head;
	    while (p != NULL)
	    {
		    ListNode *r = p->next;
		    p->next = q;
		    q = p;
		    p = r;
	    }

	    head->next = NULL;
	    return q;
    }
};