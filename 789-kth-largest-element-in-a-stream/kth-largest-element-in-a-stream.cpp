class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>minHeap;
    int siz;
    KthLargest(int k, vector<int>& nums) {
        siz = k;

        for(auto it:nums){
            minHeap.push(it);

            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);

        if(minHeap.size()>siz){
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