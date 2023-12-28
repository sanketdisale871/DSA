class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int,int>>adj[n];

    for(auto it:flights){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v,wt});
    }

    vector<int>dist(n,INT_MAX);
    dist[src]=0;

    // pair<stops,pair<price,node>>
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minHeap;

    minHeap.push({0,{0,src}});

    while(!minHeap.empty()){
        auto it = minHeap.top();minHeap.pop();

        int st = it.first;
        int pr = it.second.first;
        int node = it.second.second;

        if(st>k){
            break;
        }

        for(auto it:adj[node]){
            int adjNode = it.first;
            int adjCost = it.second;

            if(pr+adjCost<dist[adjNode]){
                dist[adjNode]=pr+adjCost;
                minHeap.push({st+1,{dist[adjNode],adjNode}});
            }
        }
    }

    if(dist[dst]==INT_MAX){
        return -1;
    }

    return dist[dst];

    }
};