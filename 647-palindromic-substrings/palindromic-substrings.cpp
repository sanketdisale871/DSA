class Solution {
public:
    typedef long long int ll;
    int countSubstrings(string s) {
        ll n = s.length();
        // Step1 : Marking a string Palindrome from [i.....j]

        vector<vector<ll>>dp(n+1,vector<ll>(n+1)); // dp[i][j] -> Will tell me the is A palindrome from (i...j)

        vector<vector<ll>>dp1(n+1,vector<ll>(n+1)); // dp[i][j] -> Wii tell me the number of Palindromes from (i..j)

        // One length Always Palindrome 
        for(ll i=1;i<=n;i++){
            dp[i][i]=1;
            dp1[i][i]=1;
        }

        // Two Length : aa,ab 
        for(ll i=1;i<n;i++){
            if(s[i-1]==s[i]){
                dp[i][i+1]=1;
            }
            // Two Length 
            dp1[i][i+1]=dp1[i][i]+dp1[i+1][i+1]+dp[i][i+1];
        }

        // 3 Length : aaa,aba,abc 
        ll len = 3;
        while(len<=n){
           
           ll i=1;
           while(i<=(n-len+1)){
               ll j = i+len-1;
               if(s[i-1]==s[j-1] && dp[i+1][j-1]==1){
                   dp[i][j]=1;
               }
               else{
                   dp[i][j]=0;
               }

               dp1[i][j]=dp1[i][j-1]+dp1[i+1][j]-dp1[i+1][j-1]+dp[i][j];
               i++;
           }
           len++;
        }
        return (int)dp1[1][n];
    }
};