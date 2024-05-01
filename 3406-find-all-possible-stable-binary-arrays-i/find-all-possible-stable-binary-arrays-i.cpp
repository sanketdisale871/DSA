class Solution {
    private:
     typedef long long int ll;
    vector<vector<vector<ll>>>dp;
     const int mod = 1e9+7;
    ll findNoSub(ll zero,ll one,ll limit,ll conElem){
        // base cas e
        if(zero==0 && one==0){
            return 1;
        }

        if(dp[zero][one][conElem]!=-1){
            return dp[zero][one][conElem]%mod;
        }

        ll ans = 0;
        if(conElem!=0){
            for(ll i=1;i<=min(zero,limit);i++){
                ans = (ans + findNoSub(zero-i,one,limit,0))%mod;
            }
        }

        if(conElem!=1){
            for(ll i=1;i<=min(one,limit);i++){
                ans = (ans + findNoSub(zero,one-i,limit,1))%mod;
            }
        }

        return dp[zero][one][conElem]=ans%mod;
    }
public:
   
    int numberOfStableArrays(int zero, int one, int limit) {
        // cout<<"Ram Krishan Hari!!<<endl;
       
        dp = vector<vector<vector<ll>>>(zero+1,vector<vector<ll>>(one+1,vector<ll>(3,-1)));

        return findNoSub(zero,one,limit,2);
    }
};