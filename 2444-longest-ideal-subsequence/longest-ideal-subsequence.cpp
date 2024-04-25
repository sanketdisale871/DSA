class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();

        int maxiAns = 1;
        vector<int>dp(n+1,1);

        vector<int>cntUpt(26,0);

        cntUpt[s[0]-'a']=1;

        for(int i=1;i<n;i++){
            char ch = s[i];
            int ind = ch-'a';

            int lwrBnd = max(0,ind-k);
            int uprBnt = min(25,ind+k);

            int maxiLem = *max_element(cntUpt.begin()+lwrBnd,cntUpt.begin()+uprBnt+1);

            dp[i]=1+maxiLem;
            cntUpt[ind]=dp[i];

            maxiAns = max(maxiAns,dp[i]);

            // cout<<"Ind : "<<ind<<" lwrBnd : "<<lwrBnd<<" uprBnt "<<uprBnt<<" s[i] "<<s[i]<<endl;
            // cout<<"dp[i] : "<<dp[i]<<endl;
        }

        return maxiAns;
    }
};