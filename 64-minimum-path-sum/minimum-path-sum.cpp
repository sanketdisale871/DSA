class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,0));

        dp[0][0]=grid[0][0];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                }
                else{
                    int op1 = INT_MAX;
                    int op2 = INT_MAX;

                    if(i-1>=0){
                        op1 = dp[i-1][j];
                    }

                    if(j-1>=0){
                        op2 = dp[i][j-1];
                    }
                    
                    dp[i][j]=grid[i][j]+min(op1,op2);
                }
            }
        }
        return dp[m-1][n-1];
    }
};