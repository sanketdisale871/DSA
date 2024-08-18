class Solution {
public:
    typedef long long int ll;
    long long maxEnergyBoost(vector<int>& eA, vector<int>& eB) {
        ll n = eA.size();

        vector<ll>dpA(n+1,0);
        vector<ll>dpB(n+1,0);
        dpA[1]=eA[0];
        dpB[1]=eB[0];

        ll ans = 0;

        for(ll i=2;i<=n;i++){
            dpA[i]=eA[i-1]+max(dpA[i-1],dpB[i-2]);
            dpB[i]=eB[i-1]+max(dpB[i-1],dpA[i-2]);

            ans = max({ans,dpA[i],dpB[i]});
        }
        return ans;
    }
};