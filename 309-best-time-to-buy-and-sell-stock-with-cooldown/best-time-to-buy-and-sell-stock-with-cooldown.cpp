class Solution {
    private:
    typedef long long int ll;
    // unordered_map<pair<ll,bool>,ll>um;
    vector<vector<ll>>dp;

    ll findBestAnswer(vector<int>&prices,ll ind,ll isBuy){
        // base case
        if(ind>=prices.size()){
            return 0;
        }

        if(dp[ind][isBuy]!=-1){
            return dp[ind][isBuy];
        }

        if(isBuy){
            return dp[ind][isBuy]=max(-prices[ind]+findBestAnswer(prices,ind+1,0),findBestAnswer(prices,ind+1,1));
        }
        else{
            return dp[ind][isBuy]=max(prices[ind]+findBestAnswer(prices,ind+2,1),findBestAnswer(prices,ind+1,0));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        dp.resize(5001,vector<ll>(2,-1));
        return (int)findBestAnswer(prices,0,true);
    }
};