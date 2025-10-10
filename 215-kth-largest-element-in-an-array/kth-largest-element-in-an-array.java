class Solution {
    public int findKthLargest(int[] nums, int k) {
        // minHeap 
        PriorityQueue<Integer>minHeap = new PriorityQueue<>();
        
        int n = nums.length;

        for(int i=0;i<n;i++){
            minHeap.add(nums[i]);
            if(minHeap.size()>k){
                minHeap.poll(); // remove wala function bhaiii
            }
        }

        return minHeap.peek();
    }
}