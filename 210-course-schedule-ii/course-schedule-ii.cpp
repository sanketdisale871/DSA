class Solution {
    private:
    vector<int>topoSort(int n,vector<int>adj[]){
        vector<int>indeg(n,0);
        vector<int>res;

        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto it = q.front();q.pop();
            res.push_back(it);

            for(auto node:adj[it]){
                indeg[node]--;

                if(indeg[node]==0){
                    q.push(node);
                }
            }            
        }

        return res;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>ans;

        vector<int>adj[n];

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
         ans= topoSort(n,adj);

         if(ans.size()!=n){
            return {};
         }
         return ans;

        // return ans;
    }
};