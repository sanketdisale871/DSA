class NumMatrix {
public:
    vector<vector<int>>preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        preSum.resize(m+1,vector<int>(n+1,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int pr = i+1;
                int pc = j+1;

                preSum[pr][pc]=preSum[pr][pc-1]+preSum[pr-1][pc]+matrix[i][j]-preSum[pr-1][pc-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       
       int ur=row1+1;
       int uc=col1+1;
       int lr=row2+1;
       int lc=col2+1;

        return preSum[lr][lc]-preSum[lr][uc-1]-preSum[ur-1][lc]+preSum[ur-1][uc-1];
    }
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
*/