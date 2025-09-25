class Solution {
    /*
     2 [5]  2+3 => 5
    3,4  2+4 => 6
   6,5,7 
  4,1,8,3

  10, => 7
  7  =>

  5
    */
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        // Initialization
        for(int j=0;j<m;j++){
            dp[m-1][j]=triangle[m-1][j]; 
            // dp[m-1][j]= trianlge[m-1][j]
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
        

    }
};