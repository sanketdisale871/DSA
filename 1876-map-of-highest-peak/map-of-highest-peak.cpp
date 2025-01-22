class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));

        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            auto node = q.front();q.pop();
            int x = node.first;
            int y = node.second;

            int drow[]={-1,1,0,0};
            int dcol[]={0,0,-1,1};

            for(int i = 0;i<4;i++){
                int newX = drow[i]+x;
                int newY = dcol[i]+y;

                if((newX>=0 && newX<m) && (newY>=0 && newY<n)){
                    if(dist[x][y]+1<dist[newX][newY]){
                        dist[newX][newY]=dist[x][y]+1;
                        q.push({newX,newY});
                    }
                }
            } 
        }
        return dist;
    }
};