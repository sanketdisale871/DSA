#include <bits/stdc++.h> 

void prepareAdjacacyList(vector<pair<int, int>> &edges,unordered_map<int,set<int>> &adj){
    
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].insert(v);
        adj[v].insert(u);
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
  /* Preparing adjacancy list */
    unordered_map<int,set<int>>adj;
    prepareAdjacacyList(edges,adj);
    
  // creating visited vector
    vector<int>vis(vertex,0);
    vector<int>ans;
    // traverse all componenet 
    for(int i=0;i<vertex;i++){
        
        if(!vis[i]){
            
            queue<int>q;
            q.push(i);
            vis[i]=1;
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                
                for(auto it : adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
    }
    
    return ans;
    
}
