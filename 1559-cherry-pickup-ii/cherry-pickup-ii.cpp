class Solution {
    private:
    typedef long long int ll;

    int dp[72][72][72];
    ll findMaxiCherry(ll i,ll j1,ll j2,ll m,ll n,vector<vector<int>>&grid){
        // Base case : Out of bound wali
        if(j1<0 || j1>=n || j2<0 || j2>=n){
            return -1e8;
        }

        // Base case : reaching to destination 
        if(i==m-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }

        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }

        ll maxi = -1e8;
        // Traverse all possible paths 
        for(ll dj1=-1;dj1<=1;dj1++){
            for(ll dj2=-1;dj2<=1;dj2++){

                if(j1==j2){
                    maxi = max(maxi,grid[i][j1]+findMaxiCherry(i+1,j1+dj1,j2+dj2,m,n,grid));
                }
                else{
                    maxi = max(maxi,grid[i][j1]+grid[i][j2]+findMaxiCherry(i+1,j1+dj1,j2+dj2,m,n,grid));
                }
            }
        }
        return dp[i][j1][j2] = maxi;
            }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();

        memset(dp,-1,sizeof(dp));

        return findMaxiCherry(0,0,n-1,m,n,grid);
    }
};