class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thDist) {
        vector<vector<int>>mat(n,vector<int>(n,1e9));

        for(int i=0;i<n;i++){
            mat[i][i]=0;
        }

        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            mat[u][v]=wt;
            mat[v][u]=wt;
        }

        for(int vai = 0;vai<n;vai++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j],mat[i][vai]+mat[vai][j]);
                }
            }
        }

        int rechCity = INT_MAX;
        int ans = -1;

        for(int city=0;city<n;city++){
            int reCh=0;
            for(int j=0;j<n;j++){
                if(city==j){
                    continue;
                }
                if(mat[city][j]<=thDist){
                    reCh++;
                }
            }
            if(reCh<=rechCity){
                ans = city;
                rechCity = reCh;
            }  
        }
        
        return ans;
    }
};