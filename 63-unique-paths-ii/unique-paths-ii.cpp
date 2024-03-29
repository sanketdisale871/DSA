class Solution {
public:
    typedef long long int ll;

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1){
            return 0;
        }

        vector<vector<ll>>dp(m+1,vector<ll>(n+1,0));

        dp[1][1]=1;

        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=n;j++){
                if(i==1 && j==1){
                    dp[i][j]=1;
                }
                else if(obstacleGrid[i-1][j-1]==1){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return (int)dp[m][n];
    }
};