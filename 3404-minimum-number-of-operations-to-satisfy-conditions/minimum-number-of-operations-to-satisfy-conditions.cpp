class Solution {
    private:
    vector<vector<int>>dp;
    int solve(int col,int keep,vector<vector<int>>&grid){
        if(col>=grid[0].size()){
            return 0;
        }

        if(dp[col][keep]!=-1){
            return dp[col][keep];
        }
        
        int cnt = 0;
        for(int r=0;r<grid.size();r++){
            if(grid[r][col]!=keep){
                cnt++;
            }
        }

        int ans = INT_MAX;
        for(int j=0;j<=9;j++){
            if(j!=keep){
                ans = min(ans,cnt+solve(col+1,j,grid));
            }
        }

        return dp[col][keep]=ans;
    }
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid[0].size();
        dp.assign(n+1,vector<int>(10,-1));
        int minAns = INT_MAX;

        for(int j=0;j<=9;j++){
            minAns = min(minAns,solve(0,j,grid));
        }
        return minAns;
    }
};