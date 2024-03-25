class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();


        bool isOneFound = false;
        for(auto it:nums){
            if(it==1){
                isOneFound = true;
            }
        }

        if(isOneFound){

            // make all are inclusive [1,...n]
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

            // Traverse and Find Out the which one is missing 
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