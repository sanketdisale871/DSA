class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        priority_queue<long long,vector<long long>,greater<long long>>minHeap;
        
        long long cost = 0;
        
        for(long long i = 0;i<n;i++){
            minHeap.push(arr[i]);
        }
        
        while(minHeap.size()>1){
            long long rope1 = minHeap.top();
            minHeap.pop();
            
            long long rope2 = minHeap.top();
            minHeap.pop();
            
            long long val = rope1 + rope2;
            
            cost+=val;
            
            minHeap.push(val);
            
        }
        return cost;
    }
};
