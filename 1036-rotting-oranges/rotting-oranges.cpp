class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // pair<node,dist>
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }

        int maxiTime = 0;

        int drow[] ={-1,1,0,0};
        int dcol[] ={0,0,1,-1};

        while(!q.empty()){
            auto it = q.front();q.pop();
            int u = it.first.first;
            int v = it.first.second;
            int wt = it.second;

            maxiTime = max(maxiTime,wt);

            for(int i=0;i<4;i++){
                int newX = drow[i]+u;
                int newY = dcol[i]+v;

                if((newX>=0 && newX<m) && (newY>=0 && newY<n) && grid[newX][newY]==1){
                    grid[newX][newY]=2;
                    q.push({{newX,newY},wt+1});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return maxiTime;
    }
};