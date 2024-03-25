class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // pair<t,pair<r,c>>
        queue<pair<int,pair<int,int>>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }

        int ans = 0;

        while(!q.empty()){
            auto it = q.front();q.pop();

            ans = max(ans,it.first);
            int x = it.second.first;
            int y = it.second.second;

            int drow[] = {-1,1,0,0};
            int dcol[] = {0,0,-1,1};

            for(int i=0;i<4;i++){
                int newX = x+drow[i];
                int newY = y+dcol[i];

                if((newX>=0 && newX<m) && (newY>=0 && newY<n) && 
                grid[newX][newY]==1){
                    grid[newX][newY]=-1;
                    q.push({it.first+1,{newX,newY}});
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

        return ans;
    }
};