class Solution {
    private:
    vector<vector<int>>dp;
    int solve(string str1,string str2,int len1,int len2){
        // Base case
        if(len1==0){
            return len2;
        }

        if(len2==0){
            return len1;
        }

        if(dp[len1][len2]!=-1){
            return dp[len1][len2];
        }

        if(str1[len1-1]==str2[len2-1]){
            return dp[len1][len2] = solve(str1,str2,len1-1,len2-1);
        }
        else{
            int ins = 1 + solve(str1,str2,len1,len2-1);
            int del = 1 + solve(str1,str2,len1-1,len2);
            int upd = 1 + solve(str1,str2,len1-1,len2-1);

            return dp[len1][len2] = min({ins,del,upd});
        }
    }
public:
    typedef long long int ll;
    int minDistance(string word1, string word2) {
        ll len1 = word1.length();
        ll len2 = word2.length();
        dp.assign(word1.length()+1,vector<int>(word2.length()+1,0));
        // return solve(word1,word2,word1.length(),word2.length());
       
       

        for(ll i=0;i<=len1;i++){
            dp[i][0]=i;
        }

        for(ll i=0;i<=len2;i++){
            dp[0][i]=i;
        }

        dp[0][0]=0;

        for(ll i=1;i<=len1;i++){
            for(ll j=1;j<=len2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    ll opt1 = 1 + dp[i][j-1];
                    ll opt2 = 1 + dp[i-1][j];
                    ll opt3 = 1 + dp[i-1][j-1];

                    dp[i][j]=min({opt1,opt2,opt3});
                }
            }
        }
        return dp[len1][len2];
    }
};