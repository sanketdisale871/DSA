class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        // Transpose taking 
        int m = mat.size();
        int n = mat[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<=i;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }

        for(int i=0;i<m;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
        
    }
};