/*
Sort a linked list in O(n log n) time using constant space complexity.
*/
/*
对一个链表进行排序，且时间复杂度要求为 O(n log n) ，空间复杂度为常量。
一看到 O(n log n) 的排序，首先应该想到归并排序和快速排序，
但是通常我们使用这两种排序方法时都是针对数组的，现在是链表了。
归并排序法：在动手之前一直觉得空间复杂度为常量不太可能，
因为原来使用归并时，都是 O(N)的，需要复制出相等的空间来进行赋值归并。
对于链表，实际上是可以实现常数空间占用的。
利用归并的思想，递归地将当前链表分为两段，然后merge，
分两段的方法是使用 fast-slow 法，用两个指针，一个每次走两步，一个走一步，
知道快的走到了末尾，然后慢的所在位置就是中间位置，这样就分成了两段。
merge时，把两段头部节点值比较，用一个 p 指向较小的，且记录第一个节点，
然后 两段的头一步一步向后走，p也一直向后走，总是指向较小节点，
直至其中一个头为NULL，处理剩下的元素。最后返回记录的头即可。代码如下：
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;ns
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeSort(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *pos = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                pos->next = l1;
                l1 = l1->next;
            } else {
                pos->next = l2;
                l2 = l2->next;
            }
            pos = pos->next;
        }
        if (l1 == NULL) pos->next = l2;
        if (l2 == NULL) pos->next = l1;
        return head->next;
    }
    
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            if (fast->next) fast = fast->next;
            else break;
            if (fast->next) fast = fast->next;
            else break;
            if (slow) slow = slow->next;
        }
        ListNode *head2 = slow->next;
        slow->next = NULL;
        head = sortList(head);
        head2 = sortList(head2);
        return mergeSort(head, head2);
    }
};


//快排  68ms 12.30%
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
    ListNode *sortList(ListNode *head) {
        if(head==NULL) return head;
        ListNode *lRoot = new ListNode(-1);
        ListNode *rRoot = new ListNode(-1);
        ListNode *piot = head;

        ListNode *lp = lRoot,*rp = rRoot;
        ListNode *lastLeft = NULL;
        int minL=INT_MAX,minR=INT_MAX,maxL=INT_MIN,maxR=INT_MIN;
        head = head->next;
        while(head!=NULL){
            if(head->val <= piot->val){
                minL = min(minL,head->val);
                maxL = max(maxL,head->val);
                lp->next = head;
                lp = lp->next;
                head = head->next;
                lp->next = NULL;
            }
            else{
                minR = min(minR,head->val);
                maxR = max(maxR,head->val);
                rp->next = head;
                rp = rp->next;
                head = head->next;
                rp->next = NULL;
            }
        }
        if(minL==maxL)
            lp = lRoot->next;
        else
            lp = sortList(lRoot->next);

        if(minR==maxR)
            rp = rRoot->next;
        else
            rp = sortList(rRoot->next);

        lastLeft = lp;
        while(lastLeft!=NULL && lastLeft->next!=NULL) lastLeft = lastLeft->next;

        //merge
        if(lp==NULL){
            piot->next = rp;
            return piot;
        }
        else{
            lastLeft->next = piot;
            piot->next = rp;
            return lp;
        }
    }
};

//归并排序 ,64ms, 25.73%
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
    ListNode *mergeList(ListNode *l1, ListNode *l2){
        ListNode *vRoot = new ListNode(-1), *cur = vRoot;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        while(l1!=NULL){
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        while(l2!=NULL){
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
        cur->next = NULL;

        cur = vRoot->next;
        return cur;
    }
    ListNode *sortList(ListNode *head) {
        if(head==NULL || head->next==NULL) return head;

        int cnt = 0;
        ListNode *mid,*cur,*l1,*l2;
        cur = head;
        while(cur!=NULL){
            cnt++;
            cur = cur->next;
        }
        mid = head;
        for(int i=1; i<cnt/2; ++i) mid = mid->next;

        cur = mid; mid = mid->next; cur->next = NULL;
        l1 = sortList(head);
        l2 = sortList(mid);
        head = mergeList(l1,l2);
        return head;
    }
};