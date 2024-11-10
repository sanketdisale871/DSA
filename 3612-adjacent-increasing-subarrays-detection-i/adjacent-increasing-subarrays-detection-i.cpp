class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>dp(n+1,0);

        dp[1]=1;

        for(int i=2;i<=n;i++){
            if(nums[i-1]>nums[i-2]){
                dp[i]=1+dp[i-1];
            }
            else{
                dp[i]=1;
            }


            if(i-k>=1){
                if(dp[i]>=k && dp[i-k]>=k){
                    return true;
                }
            }
        }
        return false;
    }
};