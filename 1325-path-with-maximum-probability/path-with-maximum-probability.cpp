class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        priority_queue<pair<double,int>>maxHeap;

        maxHeap.push({1,start_node});

        vector<double>dist(n);
        dist[start_node]=1;

        while(!maxHeap.empty()){
            auto it = maxHeap.top();maxHeap.pop();

            int node = it.second;
            double cst = it.first;

            if(node == end_node){
                return cst;
            }

            for(auto it:adj[node]){
                int adjNode = it.first;
                double adjCst = it.second;

                if(cst * 1ll * adjCst > dist[adjNode]){
                    dist[adjNode] = cst*1ll*adjCst;
                    maxHeap.push({dist[adjNode],adjNode});
                }
            }
        }

        return 0;
    }
};