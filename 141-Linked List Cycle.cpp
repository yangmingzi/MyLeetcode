/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/
/*
关于这个问题可以参考http://leonax.net/p/1960/find-circle-in-linked-list/。
由于每一个父亲只有可能有一个孩子，故这里的环实际上是指list中某一个节点的孩子同时也是它自己或者他的祖先。
这个问题需要注意几种情况：
1. 空链表不成环

2. 一个节点自环

3. 一条链表完整成环

不能开额外的空间，即空间复杂度是o(1)。
该问题是经典面试问题，其标准解法是用两个指针，一快一慢，
如果在快的指针能够追上慢的指针，则有环，否则无环。
*/

//12ms
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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *slow, *fast;//1 node per step and 2 nodes per step
        
        if(head == NULL)
            return false;
        
        slow = head;
        fast = head -> next;
        
        while(true)
        {
            if(fast == NULL)
                return false;
            
            fast = fast -> next;
            if(fast == NULL)
                return false;
            if(fast == slow)
                return true;
                
            fast = fast -> next;
            if(fast == NULL)
                return false;
            if(fast == slow)
                return true;
            
            slow = slow -> next;
            if(fast == slow)
                return true;
        }
        
    }
};
//20ms
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
    bool hasCycle(ListNode *head) {
        if(head==NULL){return false;}
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};