class Solution {
public:
    typedef long long int ll;
    int minimumBeautifulSubstrings(string s) {
        // dp[i] ==> Minimum no.of Substring of string size 'i'.

        ll n = s.length();


        ll dp[500]={100}; // Max Intialising,, indicate, not possible for dp[i]


        dp[0] = 0; // "101" => Whose string is valid so dp[3]=1

        if(s[0]=='0'){
            dp[1]=100;
        }
        else{
            dp[1]=1;
        }

        // here i, is itr for string ,, i+1 => dp index 
        for(ll i=1;i<n;i++){
            ll j = i;

            ll answer = 100;
            while(j>=0){
                string str = s.substr(j,i-j+1);

                unsigned long deci = stoi(str,0,2);

                if(s[j]!='0' && 15625%deci == 0){
                    answer = min(answer,dp[j]+1);
                }
                j--;
            }

            dp[i+1]=answer;
        }

        if(dp[n]==100){
            return -1;
        }
        return dp[n];
    }
};