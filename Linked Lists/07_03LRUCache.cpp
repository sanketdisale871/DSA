class LRUCache {
    // DSA Student : Sanket Disale
public:
    class node{
        public:
        int key,val;
        node* next;
        node* prev;

        node(int key_,int val_){
            key = key_;
            val = val_;
        }
    };
        node* head = new node(-1,-1);
        node* tail = new node(-1,-1);

        int cap;
        unordered_map<int,node*>um;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;        
    }

    void addnode(node *newNode){
        newNode->next = head->next;
        newNode->next->prev = newNode;

        head->next = newNode;
        newNode->prev = head;
    }

    void deletenode(node *delnode){
        node *delnext = delnode->next;
        node *delprev = delnode->prev;
        delnext->prev = delprev;
        delprev->next = delnext;
    }
    
    int get(int key_) {

        if(um.find(key_)!=um.end()){
            node *resnode = um[key_];
            int res = resnode->val;

            um.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            um[key_]=head->next;
            return res;
        }
        return -1;        
    }
    
    void put(int key_, int value_) {

        if(um.find(key_)!=um.end()){
            node* existingnode = um[key_];
            um.erase(key_);
            deletenode(existingnode);
        }

        if(um.size()==cap){
            um.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key_,value_));
        um[key_]=head->next;        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
