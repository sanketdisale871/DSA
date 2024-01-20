class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        int i = 0;

        while(i<n-1){
            int a = __builtin_popcount(nums[i]);
            int b = __builtin_popcount(nums[i+1]);

            if(nums[i]>nums[i+1] && a==b){
                swap(nums[i],nums[i+1]);
                i=0;
            }
            else if(nums[i]<=nums[i+1]){
                i++;
            }
            else if(nums[i]>nums[i+1] && a!=b){
                return false;
            }
        }

        return true;
    }
};