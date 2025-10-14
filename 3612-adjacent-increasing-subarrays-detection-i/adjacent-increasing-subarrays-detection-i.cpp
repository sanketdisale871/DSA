class Solution {
    /*
    nums = [2,5,7,8,9,2,3,4,3,1], k = 3
    ind = [ 0,1,2,3,4,5,6,7,8,9]
    dp = [  1,2,3,4,5,1,2,3,1,1], k = 3
    */
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