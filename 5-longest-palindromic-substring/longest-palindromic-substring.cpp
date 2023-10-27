class Solution {
public:
    string longestPalindrome(string s) {
        /*
        Steps to Solve Problem : 
        1) Cal for Palind substring of len 1
        2) Cal for Palind substring of len 1
        3) Check for other lengths        
        */
        int n = s.length();
        int dp[n][n];

        int maxiLen = 1;
        int stPoint = 0;

// One Length wala kam
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
// Two Length wala kam
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i]){
                maxiLen = 2;
                stPoint = i-1;
                dp[i-1][i]=1;
            }
        }

        // Three and above length wala 
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j = i+k-1;

                if(dp[i+1][j-1]==1 && s[i]==s[j]){
                    dp[i][j]=1;
                    if(k>maxiLen){
                        maxiLen = k;
                        stPoint = i;
                    }
                }
            }
        }


        return s.substr(stPoint,maxiLen);

    }
};