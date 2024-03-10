class Solution {
public:
    typedef long long int ll;
    int numTilings(int n) {
        vector<ll>dp(1001,0);
        vector<ll>dpUp(1001,0);
        vector<ll>dpDn(1001,0);

        const int mod = 1e9+7;

        dp[1]=1;
        dp[2]=2;

        dpUp[1]=0;
        dpDn[1]=0;

        dpUp[2]=1;
        dpDn[2]=1;


        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dpUp[i-1]+dpDn[i-1];

            dp[i]%=mod;

            dpUp[i]=dp[i-2]+dpDn[i-1];
            dpUp[i]%=mod;
            dpDn[i]=dp[i-2]+dpUp[i-1];
            dpDn[i]%=mod;
        }

        return dp[n];
    }
};