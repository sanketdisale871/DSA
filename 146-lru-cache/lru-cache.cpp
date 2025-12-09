class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key,int val){
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
    private:
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*>um;
    int cap;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(um.find(key)==um.end()){
            return -1;
        }

        auto node = um[key];
        // delete node 
        deleteNode(node);
        um.erase(key);
        insertNode(new Node(node->key,node->val));
        um[key]=head->next;
        return node->val;        
    }
    
    void insertNode(Node* newNode){
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        prevNode->next = node->next;
        node->next->prev = prevNode;
        // delete(node);
    }
    void put(int key, int value) {
        Node* newNode = new Node(key,value);

        if(um.find(key)!=um.end()){
            auto node = um[key];
            deleteNode(node);
            um.erase(key);
        }
        else if(um.size()>=cap){
            um.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
  
            insertNode(newNode);
            um[key]=head->next;
        
    }


};