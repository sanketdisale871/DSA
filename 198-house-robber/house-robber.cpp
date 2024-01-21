class Solution {
public:
    typedef long long int ll;
    ll dp[102][2];
    int rob(vector<int>& nums) {
        
        memset(dp,0,sizeof(dp));

        int n = nums.size();

        dp[1][1]=nums[0];
        dp[1][0]=0;

        for(int i=2;i<=n;i++){

            dp[i][1]=nums[i-1]+max(dp[i-2][1],dp[i-1][0]);

            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        }
        return max(dp[n][1],dp[n][0]);
    }
};