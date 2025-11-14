class Solution {
public:
    vector<int> findOrder(int numCr, vector<vector<int>>& preq) {
        vector<int>crsSched;
        vector<int>indegree(numCr,0);
        queue<int>keepTracCrs;
        vector<vector<int>>adj(numCr);

        for(auto it:preq){
            int a = it[0];
            int b = it[1];
            indegree[a]++;
            adj[b].push_back(a);
        }

        for(int i=0;i<numCr;i++){
            if(indegree[i]==0){
                keepTracCrs.push(i);
            }
        }

        while(!keepTracCrs.empty()){
            auto it = keepTracCrs.front();keepTracCrs.pop();
            crsSched.push_back(it);

            for(auto itt:adj[it]){
                indegree[itt]--;

                if(indegree[itt]==0){
                    keepTracCrs.push(itt);
                }
            }
        }
        if(crsSched.size()==numCr){
            return crsSched;
        }

        return {};        
    }
};