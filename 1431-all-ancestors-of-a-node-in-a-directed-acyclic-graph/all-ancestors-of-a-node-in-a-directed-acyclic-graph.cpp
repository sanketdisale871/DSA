class Solution {
    private:
    void doDfsTraversal(int node,vector<int>&stData,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;

        for(auto it:adj[node]){

            if(!vis[it]){
            stData.push_back(it);
                doDfsTraversal(it,stData,vis,adj);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<vector<int>> ans;


        for(auto it:edges){
            adj[it[1]].push_back(it[0]);
        }


        for(int i=0;i<n;i++){
            vector<int>stData;
            vector<int>vis(n,0);

            doDfsTraversal(i,stData,vis,adj);

            sort(stData.begin(),stData.end());

            ans.push_back(stData);
        }
        return ans;
    }
};