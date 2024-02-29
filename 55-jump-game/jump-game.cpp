class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxiJum = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            
            if(i>maxiJum){
                return false;
            }

            maxiJum = max(maxiJum,nums[i]+i);

        }
        return true;
    }
};