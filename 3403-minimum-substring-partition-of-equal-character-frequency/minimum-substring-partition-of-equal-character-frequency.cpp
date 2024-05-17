class Solution {
public:
    typedef long long int ll;
    int minimumSubstringsInPartition(string s) {
        ll n = s.length();

        vector<ll>dp(n+2,1001);

        for(ll i=0;i<=n;i++){
            dp[i]=i+1;
        }
        dp[0]=0;
        dp[1]=1;

        for(ll i=1;i<=n;i++){
            vector<ll>freq(26,0);
            // freq[s[i-1]-'a']++;

            for(ll j=i;j>0;j--){
                bool isFolow = true;
              
                freq[s[j-1]-'a']++;
                
                ll prevFreq = -1;
                for(ll tt=0;tt<26;tt++){
                    if(freq[tt]==0){
                        continue;
                    }
                    else if(prevFreq==-1){
                        prevFreq = freq[tt];
                    }
                    else if(prevFreq!=freq[tt]){
                        isFolow = false;
                        break;
                    }
                }
                
                if(isFolow){
                    dp[i]=min(dp[i],1+dp[j-1]);
                }
            }

            cout<<" i ; "<<i<<" dp[i] : "<<dp[i]<<endl;
        }

        return dp[n];
    }
};