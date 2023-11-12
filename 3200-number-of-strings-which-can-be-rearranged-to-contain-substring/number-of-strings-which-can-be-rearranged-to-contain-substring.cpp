class Solution {
    private:
    typedef long long int ll;
    const int mod = 1e9+7;
    ll dp[100000+1][2][3][2];

    ll cntStrings(ll n,ll l,ll e,ll t){
        
        if(n==0){
            if(l>=1 && e>=2 && t>=1){
                return 1;
            }
            return 0;
        }

        if(dp[n][l][e][t] != -1){
            return dp[n][l][e][t];
        }

        ll ans = 0;

        for(ll i=0;i<26;i++){

            if(i==4 && e<2){
                ans+=(cntStrings(n-1,l,e+1,t))%mod;
            }
            else if(i==11 && l<1){
                ans+=(cntStrings(n-1,l+1,e,t))%mod;
            }
            else if(i==19 && t<1){
                ans+=(cntStrings(n-1,l,e,t+1))%mod;
            }
            else{
                ans+=(cntStrings(n-1,l,e,t))%mod;
            }
        }

        return dp[n][l][e][t]=ans%mod;
    }
public:
    int stringCount(int n) {
        memset(dp,-1,sizeof(dp));
        return (int) (cntStrings(n,0,0,0))%mod;
    }
};