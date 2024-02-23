class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>>adj[n];

        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>dist(n+1,INT_MAX);
        
        // pair<int,pair<int,int>> pair<stops,pair<cost,node>>
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minHeap;

        minHeap.push({0,{0,src}});

        dist[src]=0;

        while(!minHeap.empty()){

            auto it = minHeap.top();minHeap.pop();
            int stps = it.first;
            int cst = it.second.first;
            int node = it.second.second;

            if(stps>k){
                break;
            }


            for(auto itt:adj[node]){

                int adjNode = itt.first;
                int adjCost = itt.second;

                if(cst+adjCost<dist[adjNode]){
                    dist[adjNode]=cst+adjCost;
                    minHeap.push({stps+1,{dist[adjNode],adjNode}});
                }

            }


        }

        if(dist[dst]==INT_MAX){
            return -1;
        }

        return dist[dst];

    }
};