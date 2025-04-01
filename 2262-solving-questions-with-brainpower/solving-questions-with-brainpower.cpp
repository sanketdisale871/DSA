class Solution {
public:
    typedef long long int ll;
    long long mostPoints(vector<vector<int>>& ques) {
        ll n = ques.size();

        vector<ll>dp1(n+1,0);
        vector<ll>dp0(n+1,0);

        for(ll i=n-1;i>=0;i--){
            ll nexInd = min(ques[i][1]+i+1,n);
            
            dp1[i]=ques[i][0]+max(dp1[nexInd],dp0[nexInd]);
            dp0[i]=max(dp1[i+1],dp0[i+1]);
        }

        return max(dp1[0],dp0[0]);
    }
};