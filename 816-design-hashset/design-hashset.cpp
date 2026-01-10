class MyHashSet {
public:
    vector<list<int>>buckets;
    const int size = 1e4;
    MyHashSet() {
        buckets.resize(1e4);
    }
    
    void add(int key) {
        int bktNo = key%size;
        auto& chain = buckets[bktNo];

        for(auto &it:chain){
            if(it==key){
                return;
            }
        }

        chain.emplace_back(key);
    }
    
    void remove(int key) {
        int bktNo = key%size;
        auto& chain = buckets[bktNo];

        for(auto it=chain.begin();it!=chain.end();it++){
            if(*(it)==key){
                chain.erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int bktNo = key%size;
        auto& chain = buckets[bktNo];

        for(auto &it:chain){
            if(it==key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */