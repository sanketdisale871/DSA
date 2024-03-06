class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();


        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));

        dist[0][0]=0;

        // pair<dist,r,c>
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minHeap;
        minHeap.push({0,{0,0}});

        while(!minHeap.empty()){
            auto it = minHeap.top();minHeap.pop();
            int x = it.second.first;
            int y = it.second.second;

            int currPr = it.first;

            int drow[]={-1,1,0,0};
            int dcol[]={0,0,1,-1};

            for(int i=0;i<4;i++){
                int newX = drow[i]+x;
                int newY = dcol[i]+y;

                if((newX>=0 && newX<m) && (newY>=0 && newY<n)){
                    int ct = abs(heights[newX][newY]-heights[x][y]);
                        ct = max(ct,currPr);

                        if(ct<dist[newX][newY]){
                            dist[newX][newY]=ct;
                            minHeap.push({ct,{newX,newY}});
                        }

                }
            }
        }

        return dist[m-1][n-1];
    }
};