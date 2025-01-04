class Solution {
    private:
    int findUniqueChars(int l,int r,vector<vector<int>>&charOccur){
        int u = 0;

        for(int i=0;i<26;i++){
            int tt = charOccur[r][i]-charOccur[l-1][i];

            if(tt>0){
                u++;
            }
        }


        return u;
    }
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>>occur(26,{-1,-1});

       vector<vector<int>>charOccur(s.length(),vector<int>(26));

       for(int i=0;i<s.length();i++){
            char ch = s[i];

            if(occur[ch-'a'].first==-1){
                occur[ch-'a'].first = i;
                occur[ch-'a'].second = i;
            }
            else{
                occur[ch-'a'].second = i;
            }

            for(int t=0;t<26;t++){
                if(ch-'a'==t){
                    charOccur[i][t]= (i>0?charOccur[i-1][t]:0)+1;
                }
                else{
                      charOccur[i][t]=(i>0?charOccur[i-1][t]:0);
                }
            }
       }

       int ans = 0;

       for(auto it:occur){
   

        if(it.first != it.second){
            int r = findUniqueChars(it.first+1,it.second-1,charOccur);

            if(r>0){
                ans+=r;
            }
        }
       }
    return ans;


    }
};