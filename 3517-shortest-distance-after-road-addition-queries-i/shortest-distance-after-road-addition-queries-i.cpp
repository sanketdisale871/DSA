class Solution {
    private:
    int findDist(int n,int src,int dest,vector<vector<int>> adj){
        queue<int>q;
        q.push(src);

        vector<int>vis(n,0);
        vis[src]=1;


        int dist =1;

        while(!q.empty()){
            int siz = q.size();

            while(siz--){
                auto node = q.front();q.pop();

                if(node == dest){
                    return dist;
                }

                for(auto it:adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
            dist++;
        }
        return dist;
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);

        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }

        vector<int>ans;

        for(auto it:queries){
            int u = it[0];int v = it[1];

            adj[u].push_back(v);

            int dist = findDist(n,0,n-1,adj);

            ans.push_back(dist-1);
        }


        return ans;
    }
};