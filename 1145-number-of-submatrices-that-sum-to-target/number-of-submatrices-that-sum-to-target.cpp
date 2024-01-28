class Solution {
public:
typedef long long int ll;
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        ll m = mat.size();
        ll n = mat[0].size();
        ll ans = 0;

        vector<vector<ll>>pref(m,vector<ll>(n,0));

        for(ll i=0;i<m;i++){
            pref[i][0]=mat[i][0];
            
            for(ll j=1;j<n;j++){
                pref[i][j]=pref[i][j-1]+mat[i][j];
                // cout<<"pref[i][j] : "<<pref[i][j]<<" ";
            }
            cout<<endl;
        }

        // for(ll colStart =0;colStart<n;colStart++){
        //     for(ll colEnd=colStart;colEnd<n;colEnd++){
        //         for(ll stRow=0;stRow<m;stRow++){
        //             ll sum = 0;
        //             for(ll endRow=stRow;endRow<m;endRow++){
        //                  sum+=pref[endRow][colEnd]-(colStart?pref[endRow][colStart-1]:0);

        //                  if(sum==target){
        //                      ans++;
        //                  }
        //             }
        //         }
        //     }
        // }

            for(ll stCol=0;stCol<n;stCol++){
                for(ll endCol=stCol;endCol<n;endCol++){
                    unordered_map<ll,ll>um;
                    um[0]=1;
                    ll sum = 0;

                    for(ll r=0;r<m;r++){
                        sum+=pref[r][endCol]-(stCol > 0 ? pref[r][stCol-1]:0);

                        ans+=um[sum-target];

                        um[sum]++;
                    }
                }
            }

        // unordered_map<int, int> counter;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         counter = {{0,1}};
        //         int cur = 0;
        //         for (int k = 0; k < m; k++) {
        //             cur += pref[k][j] - (i > 0 ? pref[k][i - 1] : 0);
        //             ans += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
        //             counter[cur]++;
        //         }
        //     }
        // }

        return ans;
    }
};