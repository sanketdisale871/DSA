class Solution {
public:
    int search(vector<int>& nums, int target) {
        int arraySize = nums.size();

        int low = 0;
        int high = arraySize-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(nums[low]<=nums[mid]){ // left part sorted or not
                if(nums[low]<=target && target<=nums[mid]){
                        high = mid-1;
                    }
                    else{
                        low = mid+1;
                    }
            }
            else{
                if(nums[mid]<=target && target<=nums[high]){ // Right part sorted or not
                     low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};