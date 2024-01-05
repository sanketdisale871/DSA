class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n+1,1); // one element is always greater one

        // dp[i] --> Maximum length [1 ...... i] 

        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){

                if(nums[i-1]>nums[j-1]){
                    dp[i]=max(dp[i],1+dp[j]);
                }

            }
        }

        return *max_element(dp.begin(),dp.end());

        // T.C : O(n2 + n)  S.C : O(1)
    }
};