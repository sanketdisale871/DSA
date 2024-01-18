class Solution {
public:
    typedef long long int ll;
    int climbStairs(int n) {
        // dp[n] => Total ways to reach the nTH destination 

        vector<ll>dp(n+1);

        dp[1]=1;

        if(n>1){
            dp[2]=2;
        }

        for(ll i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        return (int)dp[n];
    }
};