class Solution {
    private:
    void dfs(int r,int c,vector<vector<char>>&grid,vector<vector<int>>&vis){
        vis[r][c]=1;

        int drow[]={-1,1,0,0};
        int dcol[]={0,0,1,-1};

        for(int i=0;i<4;i++){
            int newX = drow[i]+r;
            int newY = dcol[i]+c;


            if((newX>=0 && newX<grid.size()) && (newY>=0 && newY<grid[0].size()) && grid[newX][newY]=='1'
            && !vis[newX][newY]){
                dfs(newX,newY,grid,vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        int cnt = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};