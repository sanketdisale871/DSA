class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // I have to return the Kth largest element from the array 
        // By using minHeap I can solve 
        priority_queue<int,vector<int>,greater<int>>minHeap;

        for(int i=0;i<nums.size();i++){
            // I have return the kTH largest element bhaii 
            minHeap.push(nums[i]);

            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};