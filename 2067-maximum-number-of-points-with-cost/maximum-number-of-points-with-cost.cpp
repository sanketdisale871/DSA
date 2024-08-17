class Solution {
public:
typedef long long int ll;
    long long maxPoints(vector<vector<int>>& pts) {
        ll m = pts.size();
        ll n = pts[0].size();

        ll ans = 0;

        vector<vector<ll>>dp(m,vector<ll>(n,0));

        for(int j=0;j<n;j++){
            dp[0][j]=pts[0][j];
            ans = max(ans, dp[0][j]);
        }

        for(ll i=1;i<m;i++){

            vector<ll>lef(n,0);
            vector<ll>rig(n,0);

            lef[0]=dp[i-1][0];

            for(ll k=1;k<n;k++){  // abs(k-j),, for left side j>k, so abs(k-j) = j-k => -(j-k) => k-j
                lef[k]=max(lef[k-1],k+dp[i-1][k]);
            }

            rig[n-1]=dp[i-1][n-1]-(n-1);

            for(ll k=n-2;k>=0;k--){
                rig[k]=max(rig[k+1],dp[i-1][k]-k);
            }

            for(ll j=0;j<n;j++){
                ll curr = max(lef[j]-j,rig[j]+j);
                dp[i][j]=curr+pts[i][j]; 
                ans = max(ans,dp[i][j]);
            }
        }

        return ans;
    }
};