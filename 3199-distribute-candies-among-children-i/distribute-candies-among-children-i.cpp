class Solution {
    private:
    typedef long long int ll;
    vector<vector<int>>dp;
    ll findWays(int stud,int n,int limit){
        // Base case
        if(stud==3){
            if(n==0){
                return 1;
            }
            return 0;
        }

        if(n==0){
            return 1;
        }

        if(dp[n][stud]!=-1){
            return dp[n][stud];
        }

        ll ans =0;

        for(int i=0;i<=min(limit,n);i++){
            ans+=findWays(stud+1,n-i,limit);
        }

        return dp[n][stud]=ans;
    }


public:
    int distributeCandies(int n, int limit) {
        dp.assign(n+1,vector<int>(3,-1));
        return findWays(0,n,limit);
    }
};