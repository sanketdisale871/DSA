class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m  = rowSum.size();
        int n = colSum.size();

        vector<vector<int>>ans(m,vector<int>(n,0));

        vector<int>currCol(n,0);

        for(int i=0;i<m;i++){
            int currSum =0;
            for(int j=0;j<n;j++){
                int op1 = rowSum[i]-currSum;
                int op2 = colSum[j]-currCol[j];

                ans[i][j]=min(op1,op2);
                currCol[j]+=ans[i][j];
                currSum+=ans[i][j];            }
        }
        return ans;
    }
};