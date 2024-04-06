class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<int>>dp(n,vector<int>(n,0));

        int stInd = 0;
        int maxiLen = 1;

        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }

        // Len 2 
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i]){
                dp[i-1][i]=1;

                if(2>maxiLen){
                    maxiLen = 2;
                    stInd = i-1;
                }
            }
        }

        int len = 3;

        while(len<=n){
            int i = 0;
            
            while(i<=(n-len)){
                int j = i+len-1;

                if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j]=1;

                    if(len>maxiLen){
                        maxiLen = len;
                        stInd = i;
                    }
                }
                i++;
            }
            len++;
        }

        return s.substr(stInd,maxiLen);
    }
};