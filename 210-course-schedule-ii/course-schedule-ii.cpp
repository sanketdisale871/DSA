class Solution {
    private:
    vector<int>kahnsAlgo(vector<int>adj[],int n){
        vector<int>indeg(n,0);

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

        vector<int>ans;

        while(!q.empty()){
            auto it = q.front();q.pop();
            ans.push_back(it);
            for(auto itt:adj[it]){
                indeg[itt]--;

                if(indeg[itt]==0){
                    q.push(itt);
                }
            }
        }
        return ans;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>adj[n];

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int>res = kahnsAlgo(adj,n);

        if(res.size()!=n){
            return {};
        }

        return res;
    }
};