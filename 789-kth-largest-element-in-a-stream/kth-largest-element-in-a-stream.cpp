class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>minHeap;
    int kE;

    KthLargest(int k, vector<int>& nums) {
        kE = k;
        for(auto it:nums){
            minHeap.push(it);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>kE){
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */