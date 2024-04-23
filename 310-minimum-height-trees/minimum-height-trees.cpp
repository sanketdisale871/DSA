class Solution {
    private:
    vector<int>toTopoSortLast(int n,vector<int>adj[]){
        vector<int>indeg(n,0);

        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(indeg[i]==1){
                q.push(i);
            }
        }

        vector<int>ans;

        while(!q.empty()){
            int siz = q.size();
            vector<int>temp;

            for(int i=0;i<siz;i++){
                auto it = q.front();q.pop();
                temp.push_back(it);

               for(auto itt:adj[it]){
                    indeg[itt]--;

                    if(indeg[itt]==1){
                        q.push(itt);
                    }
               }

            }
            ans = temp;
        }
        return ans;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];

        if(n==1){
            return {0};
        }

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        return toTopoSortLast(n,adj);

    }
};