class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indeg(n,0);

        for(auto it:edges){
            int u = it[0];
            int v = it[1];

            indeg[v]++;
        }

        int ans = -1;

        for(int i=0;i<n;i++){
            if(indeg[i]==0 && ans==-1){
                ans = i;
            }
            else if(indeg[i]==0 && ans!=-1){
                return -1;
            }
        }
        return ans;
    }
};