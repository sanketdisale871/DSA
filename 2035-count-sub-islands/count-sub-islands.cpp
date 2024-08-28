class Solution {
    private:
    void dfs(int i,int j,vector<vector<int>>& grid1,vector<vector<int>>& grid2,vector<vector<int>>& vis,bool &res){
        vis[i][j]=1;

        // cout<<" call i : "<<i<<" j : "<<j<<endl;

        if(grid1[i][j]!=1){
            res= false;
        }

        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};

        for(int it=0;it<4;it++){
            int newX = drow[it]+i;
            int newY = dcol[it]+j;

            if(newX>=0 && newX<grid1.size() && newY>=0 && newY<grid1[0].size() && grid2[newX][newY]==1 && !vis[newX][newY]){
                dfs(newX,newY,grid1,grid2,vis,res);
            }
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt = 0;

        int m = grid2.size();
        int n = grid2[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1 && !vis[i][j]){
                    bool res = true;

                    dfs(i,j,grid1,grid2,vis,res);
                    
                    if(res){
                        // cout<<"i : "<<i<<" j : "<<j<<endl;
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};