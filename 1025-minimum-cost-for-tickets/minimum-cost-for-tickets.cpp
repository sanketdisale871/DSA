class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int>st(days.begin(),days.end());

        vector<int>dp(366,INT_MAX);
        dp[0]=0;

        int tillMaxi = 0;

        for(int day=1;day<=365;day++){
            dp[day]=dp[day-1];

            if(st.count(day)){
                    int op1 = costs[0]+dp[day-1];
                    int op2 = costs[1]+dp[max(0,day-7)];
                    int op3 = costs[2]+dp[max(0,day-30)];

                    dp[day]=min({op1,op2,op3});
            }
        }

        return dp[365];
    }
};