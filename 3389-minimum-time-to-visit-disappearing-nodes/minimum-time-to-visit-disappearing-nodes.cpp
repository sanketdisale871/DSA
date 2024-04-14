class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>>adj[n];
        
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int l = it[2];
            adj[u].push_back({v,l});
            adj[v].push_back({u,l});
        }
        
        vector<int>ans(n,INT_MAX);
        vector<int>vis(n,0);
        ans[0]=0;
        // vis[0]=1;
        
        // pair<dist,node>
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;

        
        minHeap.push({0,0});
        
        while(!minHeap.empty()){
            auto it = minHeap.top();minHeap.pop();

            if(it.first>=disappear[it.second] || vis[it.second]){
                continue;
            }

            vis[it.second]=1;
            
            for(auto &itt : adj[it.second]){
                int adjNode = itt.first;
                int adjCst = itt.second;
                
                if(it.first+adjCst<ans[adjNode] && it.first+adjCst<disappear[adjNode]){
                    ans[adjNode]=it.first+adjCst;
                    
                    minHeap.push({it.first+adjCst,adjNode});
                }
            }
        }
        
        for(int i=0;i<ans.size();i++){
            if(ans[i]==INT_MAX){
                ans[i]=-1;
            }
        }       
        return ans;
    }
};