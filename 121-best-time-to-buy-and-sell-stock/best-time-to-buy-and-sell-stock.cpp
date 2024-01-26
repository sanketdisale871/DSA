class Solution {
public:
    typedef int ll;
    int maxProfit(vector<int>& prices) {
        ll profit = 0;
        ll mini = INT_MAX;

        for(auto num:prices){
            mini=min(mini,num);

            ll currPr = num-mini;

            profit = max(profit,currPr);
        }
        return profit;
    }
};