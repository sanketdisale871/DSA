class Solution {
    private:
    void doDfsTrav(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&vis){
        vis[i][j]=1;

        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};

        for(int ii=0;ii<4;ii++){
            int newX = drow[ii]+i;
            int newY = dcol[ii]+j;

            if((newX>=0 && newX<grid.size()) && (newY>=0 && newY<grid[0].size()) && (!vis[newX][newY]) && grid[newX][newY]=='1'){
                doDfsTrav(newX,newY,grid,vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    doDfsTrav(i,j,grid,vis);
                }
            }
        }

        return ans;
    }
};