class Solution {
public:
    vector<vector<int>>dp;
    int longestCommSub(string &text1,string &text2,int len1,int len2){
        // Base case
        if(len1==0 || len2==0){
            return 0;
        }

        if(dp[len1][len2]!=-1){
            return dp[len1][len2];
        }

        if(text1[len1-1]==text2[len2-1]){
            return  dp[len1][len2] = 1+longestCommSub(text1,text2,len1-1,len2-1);
        }
        else{
            return  dp[len1][len2] = max(longestCommSub(text1,text2,len1,len2-1),longestCommSub(text1,text2,len1-1,len2));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {

        // dp.assign(text1.length()+1,vector<int>(text2.length()+1,-1));
        // return longestCommSub(text1,text2,text1.length(),text2.length());
        int len1 = text1.length();
        int len2 = text2.length();

        int dp[len1+1][len2+1];

        // Intialisation
        for(int i=0;i<len1+1;i++){
            for(int j=0;j<len2+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }

        // actual code
        for(int i=1;i<len1+1;i++){
            for(int j=1;j<len2+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[len1][len2];
    }
};