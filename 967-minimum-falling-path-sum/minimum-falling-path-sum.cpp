class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();


        vector<vector<int>>dp(m+3,vector<int>(n+3,INT_MAX));

        for(int j=1;j<=n;j++){
            dp[1][j]=matrix[0][j-1];
        }
        int ans = INT_MAX;

        for(int i=2;i<=m;i++){
            for(int j=1;j<=n;j++){

                dp[i][j]=matrix[i-1][j-1]+min({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]});
            }           
        }

        for(int i=1;i<=n;i++){
            ans = min(ans,dp[m][i]);
        }


        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;       
    }
};