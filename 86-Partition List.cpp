//分析：只要把比x小的节点按顺序连成一条链，比x大或等于的节点连成另一条链，然后把两条链连起来。注意一下边界情况(某条链为空)
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
    ListNode *partition(ListNode *head, int x) {
        //pl指向小于x的链，pge指向大于等于x的链
        ListNode *p = head, *pl = NULL, *pge = NULL;
        //分别指向两条链的头部
        ListNode *plHead = NULL, *pgeHead = NULL;
        while(p)
        {
            if(p->val < x)
            {
                if(pl != NULL)
                {
                    pl->next = p;
                    pl = pl->next;
                }
                else
                {
                    pl = p;
                    plHead = p;
                }
            }
            else
            {
                if(pge != NULL)
                {
                    pge->next = p;
                    pge = pge->next;
                }
                else
                {
                    pge = p;
                    pgeHead = p;
                }
            }
            p = p->next;
        }
        
        if(pge != NULL)pge->next = NULL;
        if(plHead != NULL)
        {
            pl->next = pgeHead;
            return plHead;
        }
        else
            return pgeHead;
    }
};