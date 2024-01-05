class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n+1,1);

        // dp[i] --> Maximu lenght [1 ...... i] 

        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){

                if(nums[i-1]>nums[j-1]){
                    dp[i]=max(dp[i],1+dp[j]);
                }

            }
        }

        return *max_element(dp.begin(),dp.end());
    }
};