class Solution {
    public int minMoves(int[] nums) {
        int n = nums.length;
        int minMoves = 0;

        int maxElement = 0;

        for(int num:nums){
            maxElement = Math.max(num,maxElement);
        }

        for(int num:nums){
            int movesRq = maxElement - num;

            minMoves+=movesRq;
        }

        return minMoves;
    }
}