class Solution {
    private:
    typedef long long int ll;

    vector<vector<ll>>dp;
    ll findPr(ll ind,ll n,vector<int>&pr,ll buy){
        // Base case 
        if(ind>=n){
            return 0;
        }

        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }

        if(buy){
            ll opt1 = -pr[ind]+findPr(ind+1,n,pr,0);
            ll opt2 = findPr(ind+1,n,pr,1);

            return  dp[ind][buy]=max(opt1,opt2);
        }
        else{
            ll opt1 = pr[ind]+findPr(ind+1,n,pr,1);
            ll opt2 = findPr(ind+1,n,pr,0);

            return  dp[ind][buy]=max(opt1,opt2);
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        ll n  = prices.size();

        // dp.assign(n+1,vector<ll>(3,-1));

        // ll b = 1;
        // return findPr(0,prices.size(),prices,b);

        ll pr = 0;

        for(ll i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                pr+=(prices[i]-prices[i-1]);
            }
        }
        return pr;
    }
};