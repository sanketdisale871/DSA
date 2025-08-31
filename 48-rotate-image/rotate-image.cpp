class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // swap(mat[r][c],mat[c][r]);
        // Transpose of Matrix 

        for(int i=0;i<m;i++){
            for(int j=0;j<=i;j++){
                swap(mat[i][j],mat[j][i]); // Yes, ye Transpose find kar dega
            }
        }

        for(int r=0;r<m;r++){
            reverse(mat[r].begin(),mat[r].end());
        }
    }
};