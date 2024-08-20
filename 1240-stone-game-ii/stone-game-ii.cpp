class Solution {
    private:
    typedef long long int ll;
    ll dp[2][101][101];

    ll findAliceStones(ll ind,ll m,ll isAlice,vector<int>&piles){
        if(ind>=piles.size()){
            return 0;
        }

        if(dp[isAlice][ind][m]!=-1){
            return dp[isAlice][ind][m];
        }

        ll result = isAlice?-1:INT_MAX;
        ll stones = 0;
        ll n = piles.size();
        for(ll x=1;x<=min(2*m,n-ind);x++){
            stones+=piles[ind+x-1];

            if(isAlice){
                result = max(result,stones+findAliceStones(ind+x,max(m,x),0,piles));
            }
            else{
                result = min(result,findAliceStones(ind+x,max(m,x),1,piles));
            }
        }

        return dp[isAlice][ind][m]=result;
    }
public:
    int stoneGameII(vector<int>& piles) {
        ll ind = 0;
        ll m = 1;
        ll isAlice = 1;

        for(ll i=0;i<2;i++){
            for(ll j=0;j<101;j++){
                for(ll k=0;k<101;k++){
                    dp[i][j][k]=-1;
                }
            }
        }

        return findAliceStones(ind,m,isAlice,piles);
    }
};