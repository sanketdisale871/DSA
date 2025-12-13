class Solution {
    private:
    bool isSafe(int cr,int cc,int rows,int cols){
        return cr>=0 && cr<rows && cc>=0 && cc<cols;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>>vis(rows,vector<int>(cols,0));
        // queue<pair<time,pair<row,col>>q
        queue<pair<int,pair<int,int>>>q;
        int minTime = 0;
        int drow[]={-1,1,0,0};
        int dcol[] = {0,0,1,-1};

        for(int tr=0;tr<rows;tr++){
            for(int tc=0;tc<cols;tc++){
                if(grid[tr][tc]==2){
                    vis[tr][tc]=1;
                    q.push({0,{tr,tc}});
                }
            }
        }

        while(!q.empty()){
            auto it = q.front();q.pop();
            int t = it.first;
            int currRow = it.second.first;
            int currCol = it.second.second;
            minTime = max(t,minTime);

            for(int i=0;i<4;i++){
                int newX = drow[i]+currRow;
                int newY = dcol[i] + currCol;

                if(isSafe(newX,newY,rows,cols) && grid[newX][newY]==1 && !vis[newX][newY]){
                    vis[newX][newY]=1;
                    q.push({t+1,{newX,newY}});
                }
            }
        }

        // Traverse the matrix and see if is any orange which is not rotten 
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return minTime;
    }
};