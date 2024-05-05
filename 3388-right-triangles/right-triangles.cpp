class Solution {
public:
    typedef long long int ll;
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        ll m = grid.size();
        int n = grid[0].size();

        vector<ll>rows1(m,0);
        vector<ll>cols1(n,0);

        // Traverse rows 
        for(ll i=0;i<m;i++){
            ll cnt = 0;
            for(ll j=0;j<n;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
            rows1[i]=cnt;
        }

        // Traverse Cols 
        for(ll j=0;j<n;j++){
            ll cnt = 0;
            for(ll i=0;i<m;i++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
            cols1[j]=cnt;
        }


        ll ans = 0;
        
        for(ll i=0;i<m;i++){
            for(ll j=0;j<n;j++){
                if(grid[i][j]==1){
                    ll row1 = rows1[i];
                    ll col1 = cols1[j];

                    ll res = (row1-1)*(col1-1);

                    ans = ans+res;
                }
            }
        }

        return ans;
    }
};