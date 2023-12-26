class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>dist(m,vector<int>(n));
        vector<vector<int>>vis(m,vector<int>(n,0));

        //  pair<dist,pair<x,y>>q
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }

        int drow[]={-1,1,0,0};
        int dcol[]={0,0,1,-1};

        while(!q.empty()){
            auto p = q.front();q.pop();

            int d = p.first;
            int x = p.second.first;
            int y = p.second.second;

            dist[x][y]=d;

            for(int i=0;i<4;i++){
                int newX = x+drow[i];
                int newY = y+dcol[i];

                if((newX>=0 && newX<m) && (newY>=0 && newY<n) && 
                mat[newX][newY]==1 && !vis[newX][newY]){
                    q.push({d+1,{newX,newY}});
                    vis[newX][newY]=1;
                }
            }
        }
        return dist;
    }
};