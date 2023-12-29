class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,1e9));

        for(int i=0;i<n;i++){
            matrix[i][i]=0;
        }

        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            matrix[u][v]=wt;
            matrix[v][u]=wt;
        }

        // Now i wil find the distance from every city to reach every other city 

        for(int vai = 0;vai<n;vai++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j]=min(matrix[i][j],matrix[i][vai]+matrix[vai][j]);
                }
            }
        }

        int ans = 0;
        int prevCnt = INT_MAX;

        // Now, I will find the cities 
        for(int city = 0;city<n;city++){
            int cnt = 0;
            for(int reach = 0;reach<n;reach++){
                if(city==reach){
                    continue;
                }

                if(matrix[city][reach]<=distanceThreshold){
                    cnt++;
                }
            }

            if(cnt<=prevCnt){
                prevCnt=cnt;
                ans = city;
            }
        }
        return ans;
    }
};