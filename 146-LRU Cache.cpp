/*
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/
/*
分析：为了保持cache的性能，使查找，插入，删除都有较高的性能，
我们使用双向链表（std::list）和哈希表（std::unordered_map）作为cache的数据结构，因为：

双向链表插入删除效率高（单向链表插入和删除时，还要查找节点的前节点）
哈希表保存每个节点的地址，可以基本保证在O(1)时间内查找节点
具体实现细节：

越靠近链表头部，表示节点上次访问距离现在时间最短，尾部的节点表示最近访问最少
查询或者访问节点时，如果节点存在，把该节点交换到链表头部，同时更新hash表中该节点的地址
插入节点时，如果cache的size达到了上限，则删除尾部节点，同时要在hash表中删除对应的项。新节点都插入链表头部。     
*/
//92ms,53.86%
class KeyValue {
public:
    int key, value;
    KeyValue *next;
    KeyValue(int key, int value) {
        next = NULL;
        this->key = key;
        this->value = value;
    }
    KeyValue() {
        this->next = NULL;
        this->key = 0;
        this->value = 0;
    }
};

class LRUCache{
private:
    void moveToTail(KeyValue *prev) {
        if (prev->next == tail) {
            return;
        }
        
        KeyValue *node = prev->next;
        prev->next = node->next;
        if (node->next != NULL) {
            hash[node->next->key] = prev;
        }
        tail->next = node;
        node->next = NULL;
        hash[node->key] = tail;
        tail = node;
    }
    
public:
    unordered_map<int, KeyValue *> hash;
    KeyValue *head, *tail;
    int capacity, size;
    
    LRUCache(int capacity) {
        this->head = new KeyValue(0, 0);
        this->tail = head;
        this->capacity = capacity;
        this->size = 0;
        hash.clear();
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }
        
        moveToTail(hash[key]);
        return hash[key]->next->value;
    }
    
    void set(int key, int value) {
        if (hash.find(key) != hash.end()) {
            hash[key]->next->value = value;
            moveToTail(hash[key]);
        } else {
            KeyValue *node = new KeyValue(key, value);
            tail->next = node;
            hash[key] = tail;
            tail = node;
            size++;
            if (size > capacity) {
                hash.erase(head->next->key);
                head->next = head->next->next;
                if (head->next != NULL) {
                    hash[head->next->key] = head;
                }
                size--;
            }
        }
    }
};
//60ms,99.48%
struct Node{
    int key;
    int value;
    Node* hashFormer;
    Node* hashNext;
    Node* queueFormer;
    Node* queueNext;
};

class LRUCache{
public:
    Node **hashTable;
    Node* head;
    Node* tail;
    int size,hashKey,cacheCapacity;
    LRUCache(int capacity) {
        size=0;
        cacheCapacity=capacity;
        hashKey=capacity*3;
        hashTable=new Node*[capacity*3];
        head=tail=NULL;
        for(int i=0;i<capacity*3;i++){
            hashTable[i]=new Node;
            hashTable[i]->key=hashTable[i]->value=-1;
            hashTable[i]->hashFormer=hashTable[i]->hashNext=hashTable[i]->queueFormer=hashTable[i]->queueNext=NULL;
        }
    }
    
    int get(int key) {
        Node* p=hashTable[key%hashKey]->hashNext;
        while(p)
        {
            if(p->key==key)
                break;
            p=p->hashNext;
        }
        if(p==NULL)
            return -1;
        else{
            if(p->queueFormer){
                if(p->queueNext==NULL){
                    tail=p->queueFormer;
                    tail->queueNext=NULL;
                    p->queueNext=head;
                    p->queueFormer=NULL;
                    head->queueFormer=p;
                    head=p;
                }
                else{
                    p->queueFormer->queueNext=p->queueNext;
                    p->queueNext->queueFormer=p->queueFormer;
                    p->queueFormer=NULL;
                    p->queueNext=head;
                    head->queueFormer=p;
                    head=p;
                }
            }
            return p->value;
        }
    }
    
    void set(int key, int value) {
        Node* p=hashTable[key%hashKey]->hashNext;
        while(p)
        {
            if(p->key==key)
                break;
            p=p->hashNext;
        }
        if(p==NULL){
            size++;
            p=new Node;
            p->key=key;
            p->value=value;
            if(hashTable[key%hashKey]->hashNext){
                hashTable[key%hashKey]->hashNext->hashFormer=p;
            }
            p->hashFormer=hashTable[key%hashKey];
            p->hashNext=hashTable[key%hashKey]->hashNext;
            hashTable[key%hashKey]->hashNext=p;
            if(head!=NULL)
                head->queueFormer=p;
            p->queueFormer=NULL;
            p->queueNext=head;
            head=p;
            if(tail==NULL)
                tail=head;
    
            if(size>cacheCapacity){
                size--;
                tail->hashFormer->hashNext=tail->hashNext;
                if(tail->hashNext)
                    tail->hashNext->hashFormer=tail->hashFormer;
                p=tail;
                tail=tail->queueFormer;
                tail->queueNext=NULL;
                delete p;
            }
        }
        else{
            if(p->queueFormer){
                if(p->queueNext==NULL){
                    tail=p->queueFormer;
                    tail->queueNext=NULL;
                    p->queueNext=head;
                    p->queueFormer=NULL;
                    head->queueFormer=p;
                    head=p;
                }
                else{
                    p->queueFormer->queueNext=p->queueNext;
                    p->queueNext->queueFormer=p->queueFormer;
                    p->queueFormer=NULL;
                    p->queueNext=head;
                    head->queueFormer=p;
                    head=p;
                }
            }
            p->value=value;
        }
        return;
    }
};