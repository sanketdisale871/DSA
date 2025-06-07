class Solution {
    private:
    bool checkIsItValid(int currRow,int currCol,int rows,int cols){
        return currRow>=0&&currRow<rows&&currCol>=0&&currCol<cols;
    }
    void visAdjacentCells(int currRow,int currCol,vector<vector<char>>& grid,vector<vector<int>>&notVisCells){
        notVisCells[currRow][currCol]=1;

        int drow[]={-1,1,0,0};
        int dcol[]={0,0,1,-1};

        for(int itr=0;itr<4;itr++){
            int dCurrRow = currRow+drow[itr];
            int dCurrCol = currCol + dcol[itr];

            if(checkIsItValid(dCurrRow,dCurrCol,grid.size(),grid[0].size()) && grid[dCurrRow][dCurrCol]=='1' && !notVisCells[dCurrRow][dCurrCol]){
                visAdjacentCells(dCurrRow,dCurrCol,grid,notVisCells);
            }
        }
    }
public:
/*
Approach: 
1) Vis 
2) No.of Islands = No.of Calls to visite sourrounding cells;
*/
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>>notVisCells(rows,vector<int>(cols,0));

        int noOfIslands=0;

        for(int rowItr=0;rowItr<rows;rowItr++){
            for(int colItr=0;colItr<cols;colItr++){
                // Current cell is Land, and not visited
                if(grid[rowItr][colItr]=='1' && !notVisCells[rowItr][colItr]){
                    noOfIslands++;
                    visAdjacentCells(rowItr,colItr,grid,notVisCells); // Traverse the adjacent lands which can contribute in land.
                }
            }
        }

        return noOfIslands;
    }
};