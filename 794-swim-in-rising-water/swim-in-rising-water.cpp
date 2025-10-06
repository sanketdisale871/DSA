class Solution {
    private:
    bool isSafe(int r,int c,int n){
        return r>=0&&r<n&&c>=0&&c<n;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int time = 0;

        vector<vector<int>>vis(rows,vector<int>(cols,0));
        // pair<cst,pair<r,c>>
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minHeap;
        minHeap.push({grid[0][0],{0,0}});
        vis[0][0]=1;

        while(!minHeap.empty()){
            auto it = minHeap.top();minHeap.pop();
            int cst = it.first;
            int r = it.second.first;
            int c = it.second.second;
            // time = max(time,cst);

            if(r==rows-1 && c==rows-1){
                return cst;
            }

            int drow[] = {-1,1,0,0};
            int dcol[]={0,0,1,-1};

            for(int i=0;i<4;i++){
                int newX = drow[i]+r;
                int newY = dcol[i]+c;

                if(isSafe(newX,newY,grid.size()) && !vis[newX][newY]){
                    vis[newX][newY]=1;
                    int resCst = max(cst,grid[newX][newY]);
                    minHeap.push({resCst,{newX,newY}});
                }
            }
        }
        return time;
    }
};