

class LRUCache {
public:
    class node{
    public:
    int key;int val;

    node* next;
    node* prev;

    node(int key_,int val_){
        key = key_;
        val = val_;
    }
    
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    int cap ;
    unordered_map<int,node*>um;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(um.find(key)!=um.end()){
            node* temp = um[key];

            um.erase(key);
            delNode(temp);

            addNode(temp);
            um[key]=head->next;

            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(um.find(key)!=um.end()){
            node* temp = um[key];
            um.erase(key);
            delNode(temp);
        }

        if(cap == um.size()){
            node* temp = tail->prev;
            um.erase(temp->key);
            delNode(temp);
        }

        addNode(new node(key,value));
        um[key]=head->next;
    }

    void addNode(node* newNode){
            newNode->next = head->next;
            newNode->next->prev = newNode;

            head->next = newNode;
            newNode->prev = head;
    }

    void delNode(node* delNode){
        node* delPrev = delNode->prev;
        node* delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */