class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int,int>>adj[n];

        for(auto it:meetings){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<int>vis(n,0);

        vector<int> ans;

        // pair<time,PerId>
        priority_queue<pair<int,int>,vector< pair<int,int>>,greater< pair<int,int>>>minHeap;
        minHeap.push({0,0});
        minHeap.push({0,firstPerson});
        // vis[0]=1;
        // vis[firstPerson]=1;

        while(!minHeap.empty()){
            auto it = minHeap.top();minHeap.pop();
            int node = it.second;
            int time = it.first;

            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            ans.push_back(node);

            

            for(auto it:adj[node]){
                int adjNode = it.first;
                int adjTime = it.second;

                if(time<=adjTime && !vis[adjNode]){
                    // vis[adjNode]=1;
                    minHeap.push({adjTime,adjNode});
                }
            }
        }
        return ans;
    }
};