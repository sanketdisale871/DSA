class Solution {
    private:
    bool topoSort(vector<vector<int>>& cond,unordered_map<int,int>&numPosi,int k){
        vector<int>adj[k+1];

        for(auto it:cond){
            adj[it[0]].push_back(it[1]);
        }

        vector<int>indeg(k+1,0);

        for(int i=1;i<=k;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }

        queue<int>q;

        for(int i=1;i<=k;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        int idx = 0;

        while(!q.empty()){
            auto node = q.front();q.pop();

            numPosi[node]=idx;idx++;

            for(auto it:adj[node]){
                indeg[it]--;

                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }

        if(numPosi.size()>=k){
            return true;
        }
        return false;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConds, vector<vector<int>>& colConds) {
        vector<vector<int>>ans(k,vector<int>(k,0));

        unordered_map<int,int>umRowPos;

        if(!topoSort(rowConds,umRowPos,k)){
            return {};
        }

        unordered_map<int,int>umColPos;

        if(!topoSort(colConds,umColPos,k)){
            return {};
        }

        for(int i=1;i<=k;i++){
            int r= umRowPos[i];
            int c= umColPos[i];

            ans[r][c]=i;
        }

        return ans;

    }
};