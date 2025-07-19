class Solution {
    public int removeElement(int[] nums, int val) {
        // Here I have to related to Swapping Wali thing, right => Yess. 
        // I know you gone their by looking the money only, that's why this thing happened with you. Koi bhi isme kuchh nahi kr sakta hai
        // 
        // Let's place the nums[index]=nums[i]
        // Go like by this doing only. 
        /*
        nums = [3,2,2,3] val = 3
        nums = [];
        I want to think and write the code to change the things, need to be done.
         */
        int index = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=val){
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
}