class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat.size();
        vector<vector<int>>dp(m+1,vector<int>(n+3,0));

        for(int i=1;i<=n;i++){
            dp[1][i]=mat[0][i-1];
        }

        for(int i=2;i<=m;i++){
            for(int j=1;j<=n;j++){

                int opt1 = INT_MAX;
                int opt2 = INT_MAX;
                int opt3 = INT_MAX;

                if(j>1){
                    opt1 = dp[i-1][j-1];
                }

                    opt2 = dp[i-1][j];
                if(j<=n-1){
                    opt3 = dp[i-1][j+1];
                }

                dp[i][j]=mat[i-1][j-1]+min({opt1,opt2,opt3});
            }
        }


        int ans = INT_MAX;

        for(int j=1;j<=n;j++){
            ans = min(ans,dp[m][j]);
        }

        return ans;
    }
};