class Solution {
public:
    typedef long long int ll;
    int minFallingPathSum(vector<vector<int>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();

        vector<vector<ll>>dp(m,vector<ll>(n,INT_MAX));

        // Intialization 
        for(int j=0;j<n;j++){
            dp[0][j]=grid[0][j];
        }

        // Calculation wala part 

        for(ll r=1;r<m;r++){
            for(ll c=0;c<n;c++){
                for(ll trC = 0;trC<n;trC++){
                    if(trC==c){
                        continue;
                    }

                    dp[r][c]=min(dp[r][c],grid[r][c]+dp[r-1][trC]);
                }               
            }
        }

        // Finding the Minimum one Answer 
        ll ans = INT_MAX;

        for(int j=0;j<n;j++){
            ans = min(ans,dp[m-1][j]);
        }

        return ans;
    }
};