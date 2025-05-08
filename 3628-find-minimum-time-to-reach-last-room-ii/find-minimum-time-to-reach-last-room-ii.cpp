class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
      int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>minHeap;
        minHeap.push({0,0,0,0});
        vis[0][0]=1;

        while(!minHeap.empty()){
            auto it = minHeap.top();minHeap.pop();

            int r = it[2];
            int c = it[3];
            int t = it[0];
            int sc = it[1];

            if(r==m-1 && c==n-1){
                return t;
            }

            int drow[]={-1,1,0,0};
            int dcol[]={0,0,-1,1};

            for(int i=0;i<4;i++){
                int newX = drow[i]+r;
                int newY = dcol[i]+c;

                if(newX>=0 && newX<m && newY>=0 && newY<n && !vis[newX][newY]){
                    if(t>=moveTime[newX][newY]){
                        minHeap.push({t+sc+1,!sc,newX,newY});
                        vis[newX][newY]=1;
                    }
                    else{
                        int rqTime=moveTime[newX][newY]-t;
                        minHeap.push({t+rqTime+sc+1,!sc,newX,newY});
                        vis[newX][newY]=1;
                    }
                }
            }
        }
        return -1;
    }
};