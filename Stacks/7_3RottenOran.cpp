class Solution {
    // DSA Student : Sanket Disale
public:
/* Algo : 
 Time Complexity: O ( n x n ) x 4    

Reason: Worst-case – We will be making each fresh orange rotten in the grid and for each rotten orange will check in 4 directions

Space Complexity: O ( n x n )

Reason: worst-case –  If all oranges are Rotten, we will end up pushing all rotten oranges into the Queue data structure

*/
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<pair<int,int>,int>>q;

        int vis[rows][cols];

        // Storing the positioning of oranges, where it's rotten
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        int time = 0;
        // we have to check this four direction in rows and cols
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};


        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);

            for(int i=0;i<4;i++){ // checking the four directions
                int nrow = x+drow[i];
                int ncol = y + dcol[i];

                if((nrow>=0 && nrow<rows) && (ncol>=0 && ncol<cols) && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        // Confirmation of all fresh oranges, becomes to rotten
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }
        return time;
    }
};
