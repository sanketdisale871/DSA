class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();


        vector<vector<int>>vis(m,vector<int>(n,0));

//  pair<int,pair<int,int>> => time,<r,c?
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minHeap;
        minHeap.push({0,{0,0}});
        vis[0][0]=1;

        while(!minHeap.empty()){
            auto it = minHeap.top();minHeap.pop();

            int r = it.second.first;
            int c = it.second.second;
            int t = it.first;

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
                        minHeap.push({t+1,{newX,newY}});
                        vis[newX][newY]=1;
                    }
                    else{
                        int rqTime=moveTime[newX][newY]-t;
                         minHeap.push({t+rqTime+1,{newX,newY}});
                                                 vis[newX][newY]=1;

                    }
                }
            }
        }


                     return -1;

    }
};