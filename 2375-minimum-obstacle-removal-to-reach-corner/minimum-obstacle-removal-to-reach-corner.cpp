class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minHeap;
        // <cst,m,n>

        vector<vector<int>>vis(m,vector<int>(n,0));

        if(grid[0][0]==1){
            minHeap.push({1,{0,0}});
        }
        else{
            minHeap.push({0,{0,0}});
        }

        vis[0][0]=1;


        while(!minHeap.empty()){
            auto it = minHeap.top();minHeap.pop();

            int cst = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x==m-1 && y==n-1){
                return cst;
            }

            int drow []={-1,1,0,0};
            int dcol[]={0,0,1,-1};


            for(int i=0;i<4;i++){
                int newX = drow[i]+x;
                int newY = dcol[i]+y;

                if(newX>=0 && newX<m && newY>=0 && newY<n && !vis[newX][newY]){
                    if(grid[newX][newY]){
                        minHeap.push({cst+1,{newX,newY}});
                    }
                    else{
                        minHeap.push({cst,{newX,newY}});
                    }
                    vis[newX][newY]=1;
                }
            }
        }
        return -1;
    }
};