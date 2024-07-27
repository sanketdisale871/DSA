class Solution {
    private:
    vector<vector<int>>dp;
    int findOpern(string word1,string word2,int len1,int len2){
        // base case 
        if(len1==0){
            return len2;
        }

        if(len2==0){
            return len1;
        }

        if(dp[len1][len2]!=-1){
            return dp[len1][len2];
        }

        if(word1[len1-1]==word2[len2-1]){
            return dp[len1][len2]=findOpern(word1,word2,len1-1,len2-1);
        }
        else{
            int inOp = 1+findOpern(word1,word2,len1,len2-1);
            int delOp = 1 + findOpern(word1,word2,len1-1,len2);
            int rplOp = 1 + findOpern(word1,word2,len1-1,len2-1);

            return dp[len1][len2]=min({inOp,delOp,rplOp});
        }

    }
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();

        dp.resize(len1+1,vector<int>(len2+1,-1));

        return findOpern(word1,word2,len1,len2);
    }
};