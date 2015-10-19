/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/
//博客：http://blog.csdn.net/linhuanmars/article/details/22463599
//第一种算法巧夺天工，十分机敏
//画图可破之
//先合并在拆分
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 //100ms,击败100%！！！
 class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for(RandomListNode* cur = head;cur!=nullptr;){
			RandomListNode* node = new RandomListNode(cur->label);
			node->next = cur->next;
			cur->next = node;
			cur=node->next;
		}
		
		for(RandomListNode* cur=head;cur!=nullptr;){
			if(cur->random !=NULL){
				cur->next->random = cur->random->next;				
			}
			cur=cur->next->next;
		}
		RandomListNode dummy(-1);
		for(RandomListNode* cur=head,*new_cur = &dummy;cur!=nullptr;){
			new_cur->next = cur->next;
			new_cur = new_cur->next;
			cur->next = cur->next->next;
			cur = cur->next;
		}
		return dummy.next;
    }
};
/*
 class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*,RandomListNode*>relation;
		RandomListNode* copiedHead = NULL;
		RandomListNode* copiedPtr  = NULL;
		RandomListNode* ptr = head;
		
		while(ptr!=NULL){
			RandomListNode* new_node = new RandomListNode(ptr->label);
			relation.insert(pair<RandomListNode*,RandomListNode*>(ptr,new_node));
			if(copiedHead==NULL){
				copiedHead=new_node;
				copiedPtr=new_node;
			}
			else{
				copiedPtr->next = new_node;
				copiedPtr=copiedPtr->next;
			}
			copiedPtr->random = ptr->random;
			ptr=ptr->next;
		}
    }
	ptr = head;
	copiedPtr=copiedHead;
	while(ptr!=NULL){
		if(ptr->random!=NULL){
			copiedPtr->random = relation[ptr->random];
		}
		copiedPtr=copiedPtr->next;
		ptr=ptr->next;
	}
	return copiedHead;
};
*/
//108ms
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        RandomListNode* node = head;
        while(node){
            RandomListNode* newNode = new RandomListNode(node->label);
            newNode->next = node->next;
            node->next = newNode;
            node = node->next->next;
        }
        node  = head;
        while(node){
            if(node->random){
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }
        node = head;
        RandomListNode* newHead = node->next;
        while(node){
            RandomListNode* newNode = node->next;
            node->next = newNode->next;
            if(node->next){
                newNode->next = node->next->next;
            }
            node = node->next;
        }
        return newHead;
    }
};