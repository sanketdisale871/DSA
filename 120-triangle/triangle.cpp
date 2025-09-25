class Solution {
// private:
//     vector<vector<int>>dp;
// int solve(int r,int c,vector<vector<int>>& cost){
//     // If we're at the bottom row, return the value of the current cell
//     if(r==cost.size()-1){
//         return cost[r][c];
//     }

//     // If the result of variable is already calculated, return it
//     if(dp[r][c]!=-1){
//         return dp[r][c];
//     }

//     // Calculate the sum of two possible paths : Going Down and Diagonally
//     int btm = cost[r][c]+solve(r+1,c,cost);
//     int diag = cost[r][c]+solve(r+1,c+1,cost);

//     // Store the minimum of the two  paths in the dp table and return it
//     return dp[r][c]=min(btm,diag);
// }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();

        // dp.assign(m,vector<int>(n,-1));
            // return solve(0,0,triangle);
         

        /* Bootom Up Aprroach */ 

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        // Initialization
        for(int j=0;j<m;j++){
            dp[m-1][j]=triangle[m-1][j]; 
        }

        // Procedure
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int btm = triangle[i][j]+dp[i+1][j];
                int dig = triangle[i][j]+dp[i+1][j+1];

                dp[i][j]=min(btm,dig);
            }
        }
        return dp[0][0];
        

        // /* Space Optimization */
        // vector<int>next(n);
        // vector<int>curr(n);

        //   // Initialization
        // for(int j=0;j<m;j++){
        //     curr[j]=triangle[m-1][j]; 
        // }
        // next = curr;
        //         // Procedure
        // for(int i=m-2;i>=0;i--){
        //     for(int j=i;j>=0;j--){
        //         int btm = triangle[i][j]+next[j];
        //         int dig = triangle[i][j]+next[j+1];

        //         curr[j]=min(btm,dig);
        //     }
        //     next = curr;
        // }
        // return next[0];



    }
};