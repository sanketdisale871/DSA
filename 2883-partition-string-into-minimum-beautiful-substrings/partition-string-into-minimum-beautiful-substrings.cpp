class Solution {
public:
    typedef long long int ll;
    int minimumBeautifulSubstrings(string s) {
        vector<ll>dp(17,1e8);

        // dp[i] => Tell the Minimum number of substring from [1,....,i]

        int n = s.length();
        dp[0]=0;

        if(s[0]=='1'){
            dp[1]=1;
        }
        else{
            dp[1]=1e8;

        }

        for(int i=1;i<n;i++){
            int j = i;

            while(j>=0){
                string temp = s.substr(j,i-j+1);

                unsigned long dece = stoi(temp,0,2);

                if(temp[0]!='0' && 15625%dece==0){
                    dp[i+1]=min(dp[i+1],1+dp[j]);
                }
                j--;
            }
        }

        if(dp[n]==1e8){
            return -1;
        }

        return dp[n];
    }
};