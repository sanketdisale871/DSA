class Solution {
    private:
    vector<int>dp;
    int solve(int ind,string s,int n){
        // Base case
        if(ind>=n){
            return 1;
        }

        if(s[ind]=='0'){
            return 0 ;
        }

        if(dp[ind]!=-1){
            return dp[ind];
        }

        int cnt_1 = solve(ind+1,s,n);

        int cnt_2=0;
        if(ind<n-1 && s.substr(ind,2)<="26"){
            cnt_2=solve(ind+2,s,n);
        }

        return dp[ind]=cnt_1+cnt_2;
    }
public:
    int numDecodings(string s) {
        dp.assign(s.length()+1,-1);
        return solve(0,s,s.length());

    }
};