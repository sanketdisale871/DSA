class Solution {
    private:
    typedef long long int ll;
    const int mod = 1e9+7;

    ll dp[52][52][52];

    ll findWays(ll m,ll n,ll r,ll c, ll moves,ll maxMove){
        // Base case 
        if(r<0 || c<0 || r>=m || c>=n){
            return 1;
        }

        if(moves>=maxMove){
            return 0;
        }

        if(dp[r][c][moves]!=-1){
            return dp[r][c][moves];
        }

        ll temp = 0;
        temp = temp + findWays(m,n,r-1,c,moves+1,maxMove);
        temp = temp + findWays(m,n,r+1,c,moves+1,maxMove);
        temp = temp + findWays(m,n,r,c+1,moves+1,maxMove);
        temp = temp + findWays(m,n,r,c-1,moves+1,maxMove);

        return dp[r][c][moves]=temp%mod;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        for(ll i=0;i<52;i++){
            for(ll j=0;j<52;j++){
                for(ll k=0;k<52;k++){
                    dp[i][j][k]=-1;
                }
            }
        }

        return findWays(m,n,startRow,startColumn,0,maxMove);
    }
};