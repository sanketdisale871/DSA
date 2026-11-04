class Solution {
    public int minMoves2(int[] nums) {
       // 1,2,9,10 => 8 + 7 + 1 
       Arrays.sort(nums);

       int n = nums.length;
       int midElem = nums[n/2];
       int opers = 0;

       for(int num:nums){
            opers+=Math.abs(num-midElem);
       }

       return opers;
    }
}