class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>dp(m,vector<int>(n,0));
        int totCnt = 0;

        // first row as it's 
        for(int i=0;i<n;i++){
            dp[0][i]=mat[0][i];
            totCnt+=dp[0][i];
        }

        // first colum 
        for(int i=1;i<m;i++){
            dp[i][0]=mat[i][0];
            totCnt+=dp[i][0];
        }
        // cout<<"totCnt : "<<totCnt<<endl;

        // For all 
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][j]==1){
                    dp[i][j]= min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                }
                else{
                    dp[i][j]=0;
                }
                totCnt+=dp[i][j];
            }
        }
        return totCnt;
    }
};