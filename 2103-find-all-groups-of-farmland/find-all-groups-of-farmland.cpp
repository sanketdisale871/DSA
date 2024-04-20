class Solution {
    private:
    void dfsTrav(int r,int c,int &maxiR,int &maxiC,int m,int n,vector<vector<int>>&vis,vector<vector<int>>& land){
        maxiR = max(maxiR,r);
        maxiC = max(maxiC,c);

        vis[r][c]=1;


        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};

        for(int i=0;i<4;i++){
            int newR = r + drow[i];
            int newC = c + dcol[i];

            if((newR>=0 && newR<m) && (newC>=0 && newC<n) && land[newR][newC]==1 && !vis[newR][newC]){
                dfsTrav(newR,newC,maxiR,maxiC,m,n,vis,land);
            }
        }
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m = land.size();
        int n = land[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1 && !vis[i][j]){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    int maxiR = i;
                    int maxiC = j;
                    dfsTrav(i,j,maxiR,maxiC,m,n,vis,land);
                    temp.push_back(maxiR);
                    temp.push_back(maxiC);

                    ans.push_back(temp);
                }
            }
        }


        return ans;
    }
};