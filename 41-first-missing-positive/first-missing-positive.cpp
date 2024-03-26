class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        bool isOnePresent = false;

        for(int i=0;i<n;i++){
            if(nums[i]==1){
                isOnePresent = true;
            }
        }


        if(isOnePresent){
            // Mark the 1 as out of range 

            for(int i=0;i<n;i++){
                if(nums[i]<1 || nums[i]>n){
                    nums[i]=1;
                }
            }

            for(int i=0;i<n;i++){
                int ind = abs(nums[i])-1;

                if(nums[ind]>0){
                    nums[ind]=-1*nums[ind];
                }
            }

            for(int i=0;i<n;i++){
                if(nums[i]>0){
                    return i+1;
                }
            }

            return n+1;
        }
        else{
            return 1;
        }
    }
};