class Solution {
    private:
    vector<int>drow ={-1,1,0,0};
    vector<int>dcol ={0,0,1,-1};

    bool isSafe(int mid,vector<vector<int>>&dist,int m,int n){
        if(dist[0][0]<mid){
            return false;
        }

        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;

        while(!q.empty()){
            auto it = q.front();q.pop();

            int x = it.first;int y = it.second;

            if(x==m-1 && y==n-1){
                return true;
            }

            for(int i=0;i<4;i++){
                int newX = x + drow[i];
                int newY = y + dcol[i];

                if((newX>=0 && newX<m) && (newY>=0 && newY<n) && !vis[newX][newY]){
                    if(dist[newX][newY]<mid){
                        continue;
                    }
                    q.push({newX,newY});
                    vis[newX][newY]=1;
                }
            }
        }
        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        // Edge case
        if(grid.size()==1){
            return 0;
        }

        // Step 1:  Find the Minimum distance from theif
        // Step 2 : By using binary search , check the maxiMum safeness factor
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dist(m,vector<int>(n,1e9));
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    vis[i][j]=1;

                    q.push({i,j});
                }
            }
        }


        while(!q.empty()){
            auto it = q.front();q.pop();
            int x = it.first;
            int y = it.second;


            for(int i=0;i<4;i++){
                int newX = x + drow[i];
                int newY = y + dcol[i];

                if((newX>=0 && newX<m) && (newY>=0 && newY<n) && (!vis[newX][newY])){
                    
                    if(dist[x][y]+1<dist[newX][newY]){
                        dist[newX][newY]=dist[x][y]+1;
                        vis[newX][newY]=1;

                        q.push({newX,newY});
                    }
                }
            }
        }

       // Step 2 : Binary Search on dist
       int low = 0;
       int high = INT_MAX-1;
       int ans = -1;

       while(low<=high){
           int mid = low + (high-low)/2;

           if(isSafe(mid,dist,m,n)){
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