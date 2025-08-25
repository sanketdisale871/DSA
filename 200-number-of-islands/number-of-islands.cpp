class Solution {
    private:
    bool isSafe(int newX,int newY,int rows,int cols){
        return newX>=0 && newY>=0 && newX<rows && newY<cols;
    }

    void dfsTraversal(int r,int c,vector<vector<char>>&grid,vector<vector<int>>&vis){
        vis[r][c]=1;

        int drow[]={-1,1,0,0};
        int dcol[]={0,0,1,-1};

        for(int dr=0;dr<4;dr++){
            int newX = drow[dr]+r;
            int newY = dcol[dr]+c;

            if(isSafe(newX,newY,grid.size(),grid[0].size()) && grid[newX][newY]=='1' && !vis[newX][newY]){
                dfsTraversal(newX,newY,grid,vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>>vis(rows,vector<int>(cols,0));


        // Connecting adjacent cells horizontally or vertically. 
        int islands = 0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    islands++;
                    dfsTraversal(i,j,grid,vis);
                }
            }
        }

        return islands;
    }
};