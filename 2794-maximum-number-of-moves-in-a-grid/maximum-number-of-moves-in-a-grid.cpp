class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,0));


        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }

        int maxiMove = 1;

        for(int j=1;j<n;j++){
            for(int i=0;i<m;i++){

                // Uper left 
                int upperDiag = 0,currRow=0,lwrDiag=0;

                if(i-1>=0 && j-1>=0 && grid[i][j]>grid[i-1][j-1]){
                    upperDiag = dp[i-1][j-1];
                }

                if(j-1>=0 && grid[i][j]>grid[i][j-1]){
                    currRow = dp[i][j-1];
                }

                if(i+1<m && j-1>=0 && grid[i][j]>grid[i+1][j-1]){
                    lwrDiag = dp[i+1][j-1];
                }

                dp[i][j]=max({upperDiag,currRow,lwrDiag});
                if(dp[i][j]>0){
                    dp[i][j]+=1;
                }

                maxiMove = max(maxiMove,dp[i][j]);
            }
        }
        return maxiMove-1;
    }
};