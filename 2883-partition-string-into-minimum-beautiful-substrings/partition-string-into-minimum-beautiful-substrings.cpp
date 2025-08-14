class Solution {
public:
    typedef long long int ll;
    int minimumBeautifulSubstrings(string s) {
        /*
        P.S: Minimum number of substrings in such partition        
        */
        int n = s.length();
        vector<ll>dp(n+1,1e18);

        if(s[0]=='1'){
            dp[1]=1;
        }
        dp[0]=0;
        
        

        for(ll i=2;i<=n;i++){
            ll r = 1e18;
            ll j = i;
            while(j>=1){
                string temp = s.substr(j-1,i-j+1);
                unsigned long num = stoi(temp,0,2);

                if(temp[0]!='0' && 15625%num==0){
                    r = min(r,1+dp[j-1]);
                }
                j--;
            }
            dp[i]=r;
        }
        return dp[n]==1e18?-1:dp[n];
    }
};