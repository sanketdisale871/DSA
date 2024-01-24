class Solution {
public:
    typedef long long int ll;
    const int mod = 1e9+7;
    int numTilings(int n) {
        vector<ll>dp(n+2,0);
        vector<ll>upDp(n+2,0);
        vector<ll>dwDp(n+2,0);

        dp[1]=1;
        dwDp[1]=0;
        upDp[1]=0;

        dp[2]=2;
        dwDp[2]=1;
        upDp[2]=1;


        for(ll i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+upDp[i-1]+dwDp[i-1];
            dp[i]%=mod;

            upDp[i]=dp[i-2]+dwDp[i-1];
            upDp[i]%=mod;
            dwDp[i]=dp[i-2]+upDp[i-1];
            dwDp[i]%=mod;
        }

        return dp[n]; // The no.of all ways to place domino, tromino 
    }
};