class Solution {
public:
    typedef long long int ll;
    ll dp[102];
    int rob(vector<int>& nums) {
        
        memset(dp,0,sizeof(dp));

        int n = nums.size();

        dp[1]=nums[0];

        for(int i=2;i<=n;i++){
            dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
        }
        return dp[n];
    }
};