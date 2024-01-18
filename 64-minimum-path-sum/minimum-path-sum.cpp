class Solution {
public:
    typedef long long int ll;

    int minPathSum(vector<vector<int>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();

        vector<vector<ll>>dp(m+1,vector<ll>(n+1,4001));

        dp[1][1]=grid[0][0];

        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=n;j++){
                if(i==1 && j==1){
                    dp[i][j]=grid[0][0];
                }
                else{
                    dp[i][j]=grid[i-1][j-1]+min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};