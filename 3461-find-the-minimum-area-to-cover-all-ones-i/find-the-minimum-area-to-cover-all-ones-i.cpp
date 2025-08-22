class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
       int minRows = INT_MAX;
       int maxRows = INT_MIN;
       int minCols = INT_MAX;
       int maxCols = INT_MIN;
       bool isOnePres = false;

       int rows = grid.size();
       int cols = grid[0].size();

       for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(grid[i][j]==1){
                isOnePres = true;
                minRows = min(minRows,i);
                maxRows = max(maxRows,i);
                minCols = min(minCols,j);
                maxCols = max(maxCols,j);
            }
        }
       }

       if(!isOnePres){
        return 0;
       }

       int len = maxRows-minRows+1;
       int brid = maxCols-minCols+1;

       return len*brid;     
    }
};