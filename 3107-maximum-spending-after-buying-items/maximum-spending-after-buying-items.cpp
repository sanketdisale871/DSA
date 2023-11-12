class Solution {

public:
    typedef long long int ll;
    long long maxSpending(vector<vector<int>>& values) {
        ll m = values.size();
        ll n = values[0].size();
        vector<ll>vals;

        for(ll i=0;i<m;i++){
            for(ll j=0;j<n;j++){
                vals.push_back(values[i][j]);
            }
        }

        sort(vals.begin(),vals.end());
        ll ans = 0;

        for(ll i=0;i<vals.size();i++){
            ans+=(vals[i])*(i+1);
        }        
        return ans;
    }
};