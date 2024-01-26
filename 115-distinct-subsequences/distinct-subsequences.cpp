class Solution {
public:
    // typedef long long int ll;
    // ll dp[1004][1004];
    int numDistinct(string s1, string s2) {

 int len1 = s1.length();
        int len2 = s2.length();
        
        // dp.assign(len1+1,vector<int>(len2+1,-1));

        int dp[len1+1][len2+1];

    // Initialisation
        for(int i=0;i<len1+1;i++){
            for(int j=0;j<len2+1;j++){
                if(i==0){
                    dp[i][j]=0;
                }

                if(j==0){
                    dp[i][j]=1;
                }
            }
        }

        for(int i=1;i<len1+1;i++){
            for(int j=1;j<len2+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]*1LL+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        return dp[len1][len2];

    }
};