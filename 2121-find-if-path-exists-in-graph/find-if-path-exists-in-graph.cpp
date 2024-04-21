class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // BFS Traversal 
        vector<int>adj[n];

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>vis(n,0);

        queue<int>q;
        q.push(source);

        vis[source]=1;

        while(!q.empty()){
            auto it = q.front();q.pop();

            if(it==destination){
                return true;
            }

            for(auto itt:adj[it]){
                if(!vis[itt]){
                    q.push(itt);
                    vis[itt]=1;
                }
            }
        }
        return false;
    }
};