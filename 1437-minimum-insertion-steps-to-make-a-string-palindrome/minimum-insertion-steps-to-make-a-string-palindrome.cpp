class Solution {
    private:
    typedef long long int ll;

    ll lcs(string str1,string str2,ll len1,ll len2){

        vector<vector<ll>>dp(len1+1,vector<ll>(len2+1,0));

        for(ll i=1;i<= len1;i++){
            for(ll j=1;j<=len2;j++)
            {
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[len1][len2];
    }
public:
    int minInsertions(string s) {
        string str1 = s;
        reverse(s.begin(),s.end());

        return s.length()-lcs(str1,s,str1.length(),s.length());
    }
};