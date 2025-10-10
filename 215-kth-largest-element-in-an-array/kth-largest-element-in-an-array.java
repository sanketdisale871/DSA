class Solution {
    public int findKthLargest(int[] nums, int k) {
        // minHeap 
        // PriorityQueue<Integer>minHeap = new PriorityQueue<>();

        // I can sort the array also,
        Arrays.sort(nums);
        int n = nums.length;

        return nums[n-k];
    }
}