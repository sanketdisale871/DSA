class Solution {
    private:
    void dfsTrav(int r,int c,vector<vector<int>>grid,int &fishGet,vector<vector<int>>&vis){
        fishGet+=grid[r][c];
        vis[r][c]=1;

        int drow[]={-1,1,0,0};
        int dcol[]={0,0,1,-1};


        for(int i=0;i<4;i++){
            int newX = drow[i]+r;
            int newY = dcol[i]+c;

            if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && !vis[newX][newY] && grid[newX][newY]){
                dfsTrav(newX,newY,grid,fishGet,vis);
            }
        }
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();


        // 2D vector, maxFish[r][c] => Maximum Fish, fisher can catch

        vector<vector<int>>maxFish(rows,vector<int>(cols,0));

        int maxiAmnt = 0;
        int maxFishIGet=0;

        for(int trvRow=0;trvRow<rows;trvRow++){
            for(int trvCol=0;trvCol<cols;trvCol++){
                if(grid[trvRow][trvCol]==0){
                    continue;
                }
                cout<<trvRow<<" "<<trvCol<<endl;
                vector<vector<int>>vis(rows,vector<int>(cols,0));
                int fishGet = 0;
                dfsTrav(trvRow,trvCol,grid,fishGet,vis);
                cout<<fishGet<<" "<<endl;
                maxFishIGet=max(maxFishIGet,fishGet);
            }
        }
        return maxFishIGet;
    }
};