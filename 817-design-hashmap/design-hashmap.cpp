class MyHashMap {
public:
    vector<int>um;
    MyHashMap() {
        um.resize(1e6+1,-1);
    }
    
    void put(int key, int value) {
        um[key]=value;
    }
    
    int get(int key) {
        return um[key];
    }
    
    void remove(int key) {
        um[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */