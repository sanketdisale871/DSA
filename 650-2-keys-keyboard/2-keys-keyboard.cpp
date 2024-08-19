class Solution {
    private:
    int count(int currA,int copiedA,int n,vector<vector<int>>&dp){
        if(currA>n){
            return 1e6;
        }
        else if(currA==n){
            return 0;
        }

        if(dp[currA][copiedA]!=-1){
            return dp[currA][copiedA];
        }

        int copy = 2 + count(currA+currA,currA,n,dp);
        int past = 1 + count(currA+copiedA,copiedA,n,dp);

        return dp[currA][copiedA]=min(copy,past);
    }
public:
    int minSteps(int n) {
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));

        return n>1?1+count(1,1,n,dp):0;
    }
};