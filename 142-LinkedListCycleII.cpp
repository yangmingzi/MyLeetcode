/*
参见博客（思路及简洁写法）：http://www.cnblogs.com/easonliu/p/3650677.html
设第x各节点是进入循环的节点，、
在x+y个节点处相遇，相遇处距离入口处距离为Z个节点
F走的路程应该是S的两倍

S = x + y

F = x + y + z + y = x + 2y + z

2*S = F

2x+2y = x + 2y + z

得到x = z
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast != NULL) {
           
            if (fast->next != NULL) {
                fast = fast->next;
            } else {
                return NULL;
            }
            if (fast->next != NULL) {
                fast = fast->next;
            } else {
                return NULL;
            }
            if (slow == fast) {
                break;
            }

            if (slow->next != NULL) {
                slow = slow->next;
            } else {
                return NULL;
            }
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};



