class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Dekh, by using O(n), O(n), I can find easil
        // O(n) by using XOR 
        // O(log (n)) ==> Binary Search 
        int low = 0;
        int high = nums.size()-1;

        if(nums.size()==1){
            return nums[0];
        }

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] != nums[mid^1]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return nums[low];

    }
};