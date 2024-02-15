class Solution {
    private:
    bool isPossible(int mid,vector<vector<int>>dist){
        if(dist[0][0]<mid){
            return false;
        }

        int m = dist.size();
        int n = dist[0].size();

        queue<pair<int,int>>q;
        q.push({0,0});

        while(!q.empty()){
            auto it = q.front();q.pop();

            int x = it.first;
            int y = it.second;

            if(x==m-1 && y==n-1){
                return true;
            }

            int drow[] = {-1,1,0,0};
            int dcol[]= {0,0,1,-1};

            for(int i=0;i<4;i++){
                int newX = x+drow[i];
                int newY = y+dcol[i];

                if((newX>=0 && newX<m) && (newY>=0 && newY<n)){
                    if(dist[newX][newY]>=mid){
                        q.push({newX,newY});
                        dist[newX][newY]=INT_MIN;
                    }
                }
            }
        }
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dist(m,vector<int>(n,1e8));

        // pair<cost,pair<x,y>>
        queue<pair<int,pair<int,int>>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({0,{i,j}});
                    dist[i][j]=0;
                }
            }
        }

    

        while(!q.empty()){
            auto it = q.front();q.pop();
            int x = it.second.first;
            int y = it.second.second;
            int cost = it.first;

            int drow[]= {-1,1,0,0};
            int dcol[] = {0,0,-1,1};

            for(int i=0;i<4;i++){
                int newX = x+drow[i];
                int newY = y+dcol[i];

                if((newX>=0 && newX<m) && (newY>=0 && newY<n)){
                    if(cost+1<dist[newX][newY]){
                        dist[newX][newY]=cost+1;
                        q.push({cost+1,{newX,newY}});
                    }
                }
            }
        }

        int ans = -1;

        int low = 0;
        int high = INT_MAX;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossible(mid,dist)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};