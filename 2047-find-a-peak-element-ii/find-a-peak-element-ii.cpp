class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int low = 0;
        int high = cols-1;

        while(low<=high){
            int midCol = low + (high-low)/2;

            int maxRow = 0;

            for(int i=1;i<rows;i++){
                maxRow = mat[maxRow][midCol]<mat[i][midCol]?i : maxRow;
            }

            bool leftBig = midCol>low && mat[maxRow][midCol-1]>mat[maxRow][midCol]?true:false;
            bool rightBig = midCol<high && mat[maxRow][midCol+1]>mat[maxRow][midCol]?true:false;

            if(!leftBig && !rightBig){
                return {maxRow,midCol};
            }
            else if(leftBig){
                high = midCol-1;
            }
            else{
                low = midCol+1;
            }
            
        }
        return {-1,-1};
    }
};