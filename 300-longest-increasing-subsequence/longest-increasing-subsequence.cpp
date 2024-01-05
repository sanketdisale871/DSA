class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n+1,1); // one element is always greater one

        // dp[i] --> Maximum length [1 ...... i] 

        int maxi = 1;

        multiset<pair<int,int>>ml;

        ml.insert({nums[0],dp[1]});

        for(int i=2;i<=n;i++){
            
            auto it = ml.lower_bound({nums[i-1],dp[i]});

            while(it!=ml.begin()){

                it--;
                dp[i]=max(dp[i],1+(*it).second);
            }

            maxi = max(maxi,dp[i]);

            ml.insert({nums[i-1],dp[i]});
        }

        return maxi;

        // T.C : O(n*log(n))  S.C : O(n)
    }
};