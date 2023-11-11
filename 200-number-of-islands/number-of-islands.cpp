class Solution {
    private:
    void dfsTraversal(vector<vector<char>>& grid,vector<vector<int>>&vis,int currRow,int currCol){
        vis[currRow][currCol] = 1;

        vector<int>drow = {
            1,-1,0,0
        };
        vector<int>dcol={
            0,0,-1,1
        };

        for(int i=0;i<4;i++){
            int newX = currRow + drow[i];
            int newY = currCol + dcol[i];

            if((newX>=0 && newX<grid.size()) && (newY>=0 && newY<grid[0].size())
            && (grid[newX][newY]=='1') && (!vis[newX][newY])){
                // vis[newX][newY]=1;
                dfsTraversal(grid,vis,newX,newY);
            }

        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        int numIslands = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    numIslands++;
                    dfsTraversal(grid,vis,i,j);
                }
            }
        }
        return numIslands;
    }
};