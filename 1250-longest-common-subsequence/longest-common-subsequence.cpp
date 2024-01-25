class Solution {
public:
    typedef long long int ll;
    int longestCommonSubsequence(string text1, string text2) {
        ll len1 = text1.length();
        ll len2 = text2.length();

        vector<vector<ll>>dp(len1+1,vector<ll>(len2+1,0));


        for(ll i=1;i<=len1;i++){
            for(ll j=1;j<=len2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[len1][len2];
    }
};