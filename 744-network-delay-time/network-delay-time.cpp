class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];

        for(auto it:times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
        }

        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;

//  pair<dist,node>
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;

        minHeap.push({0,k});

        while(!minHeap.empty()){
            auto it = minHeap.top();minHeap.pop();

            int node = it.second;
            int ct = it.first;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjCost = it.second;

                if(ct+adjCost<dist[adjNode]){
                    dist[adjNode]=ct+adjCost;

                    minHeap.push({dist[adjNode],adjNode});
                }
            }
        }

        int minCost = *max_element(dist.begin()+1,dist.end());

        return minCost==INT_MAX?-1:minCost;

    }
};