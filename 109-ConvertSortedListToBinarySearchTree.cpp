/*
寻找根部，即找到中间点
然后调用递归
注意仅有1和2个节点的特殊情况
还要再加深对指针的理解呀！！！
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);
        ListNode *slow = head;//慢指针
        ListNode *fast = head;//快指针
        ListNode *last = slow;//跟踪慢指针，最后成为中间点前面的那个点
        while (fast->next && fast->next->next) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;//中间点后面的那个点
                         //注意这一步的顺序，当链表仅有两个元素时，不能先执行下一步
        last->next = NULL;//使下次递归时，左侧以head为起点的链截止在上次递归是的根部
        TreeNode *cur = new TreeNode(slow->val);
        //递归
        if (head != slow) cur->left = sortedListToBST(head);
        cur->right = sortedListToBST(fast);
        return cur;
    }
};