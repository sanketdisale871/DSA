class Solution {
    private:
    typedef long long int ll;
public:
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string>st(dict.begin(),dict.end());
        ll n = s.length();

        vector<ll>dp(n+1,INT_MAX);
        dp[0]=0;

        for(ll i=1;i<=n;i++){
            ll j =i;
            // cout<<" i : "<<i<<endl;
            while(j>=1){
                string str = s.substr(j-1,i-j+1);

                // cout<<"str : "<<str;

                if(st.count(str)){
                    dp[i]=min(dp[i],dp[j-1]);
                }
                else{
                    dp[i]=min(dp[i],i-j+1 + dp[j-1]);
                }
                j--;
            }

            // cout<<"i : "<<i<<" dp[i] "<<dp[i]<<endl;
        }

        return dp[n];
    }
};