class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;

        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }


        while(!q.empty()){
            int siz = q.size();

            for(int i=0;i<siz;i++){
                auto p =q.front(); q.pop();

                int currTime = p.first;
                int iNode = p.second.first;
                int jNode = p.second.second;

                time = max(time,currTime);

                int drow[]={1,-1,0,0};
                int dcol[]={0,0,1,-1};

                for(int i=0;i<4;i++){
                    int newX = drow[i]+iNode;
                    int newY = dcol[i]+jNode;

                    if((newX>=0 && newX<m) && (newY>=0 && newY<n) && (!vis[newX][newY]) && (grid[newX][newY]==1)){
                        vis[newX][newY]=1;
                        q.push({currTime+1,{newX,newY}});
                    }
                }

            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0){
                    return -1;
                }
            }
        }


        return time;
    }
};