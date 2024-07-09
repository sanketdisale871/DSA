class Solution {
public:
    typedef long long int ll;
    double averageWaitingTime(vector<vector<int>>& cust) {
        double ans = 0;
        int n = cust.size();

        ll t = 0;

        for(ll i=0;i<n;i++){
            t = max((ll)t+cust[i][1],(ll)cust[i][0]+cust[i][1]);

            int res = t-cust[i][0];

            ans+=res;
        }

        return ans*1.0/n;

    }
};