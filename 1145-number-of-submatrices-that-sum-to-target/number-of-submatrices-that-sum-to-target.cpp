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
            }
        }

        for(ll colStart =0;colStart<n;colStart++){
            for(ll colEnd=colStart;colEnd<n;colEnd++){
                for(ll stRow=0;stRow<m;stRow++){
                    ll sum = 0;
                    for(ll endRow=stRow;endRow<m;endRow++){
                         sum+=pref[endRow][colEnd]-(colStart?pref[endRow][colStart-1]:0);

                         if(sum==target){
                             ans++;
                         }
                    }
                }
            }
        }
        return ans;
    }
};