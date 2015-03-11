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