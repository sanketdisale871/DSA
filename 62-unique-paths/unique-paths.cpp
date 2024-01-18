class Solution {
public:
    typedef long long int ll;
    int uniquePaths(int m, int n) {
        vector<vector<ll>>dp(m+1,vector<ll>(n+1,0));

        dp[1][1]=1;

        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=n;j++){
                if(i==1 && j==1){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                // cout<<"i : "<<i<<" j : "<<j<<" "<<dp[i][j]<<endl;
            }
        }

        return (int)dp[m][n];
    }
};