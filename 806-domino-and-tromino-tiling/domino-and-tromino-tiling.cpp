class Solution {
public:
    typedef long long int ll;
    const int mod = 1e9+7;
    int numTilings(int n) {
        // dp[i] => Answer of Question, if Size of array is `i`. Horizontal + Vertical + UpperTrim + LowerTriam 

        vector<ll>dp(1005);
        vector<ll>dpUp(1005); // For trimino
        vector<ll>dpDw(1005); // For trimino 

        dpUp[1]=0;
        dpDw[1]=0;
        dp[1] = 1;

        dpUp[2] = 1 ;
        dpDw[2] = 1 ;
        dp[2] = 2 ;

        for(ll i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dpDw[i-1]+dpUp[i-1];
            dp[i]%=mod;

            dpUp[i]=dpDw[i-1]+dp[i-2];
            dpUp[i]%=mod;
            dpDw[i]=dpUp[i-1]+dp[i-2];
            dpDw[i]%=mod;
        }

        return dp[n];
    }
};