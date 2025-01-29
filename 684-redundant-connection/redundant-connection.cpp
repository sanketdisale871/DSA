class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        set<int>st;

        int n = edges.size();

        vector<vector<int>>adj(n+1);

        

        vector<int>indeg(n+1,0);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
            indeg[it[1]]++;
        }

        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indeg[i]==1){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto node = q.front();q.pop();
            st.insert(node);

            for(auto it:adj[node]){
                indeg[it]--;

                if(indeg[it]==1){
                    q.push(it);
                }
            }
        }

        for(int i=edges.size()-1;i>=0;i--){
            int u = edges[i][0];
            int v = edges[i][1];

            if(st.count(u)==0 && st.count(v)==0){
                return {u,v};
            }
        }
        return {0,0};
    }
};