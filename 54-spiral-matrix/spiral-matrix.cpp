class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        int stRow=0,stCol=0,endRow=m-1,endCol=n-1;

        while(ans.size()<(m*n)){
            // First Row 
            int ind = stCol;
            for(;ind<=endCol && ans.size()<(m*n) ;ind++){
                ans.push_back(mat[stRow][ind]);
            }
            stRow++;

            ind = stRow;
            for(;ind<=endRow && ans.size()<(m*n);ind++){
                ans.push_back(mat[ind][endCol]);
            }
            endCol--;

            ind = endCol;
            for(;ind>=stCol && ans.size()<(m*n);ind--){
                ans.push_back(mat[endRow][ind]);
            }
            endRow--;

            ind = endRow;
            for(;ind>=stRow && ans.size()<(m*n);ind--){
                ans.push_back(mat[ind][stCol]);
            }
            stCol++;
        }

        return ans;
    }
};