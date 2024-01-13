class Solution {
public:
    typedef long long int ll;
    
    int minimumBeautifulSubstrings(string s) {
        ll dp[500]={1000};
        
        ll n = s.length();
        
        // 0-length ke liye
        dp[0]=0;
        
        // 1-length ke liye 
        if(s[0]=='0'){
            dp[1]=1000;
            
            if(s.length()==1){
                return -1;
            }
        }
        else{
            dp[1]=1;
        }
        
        for(ll j=2;j<=n;j++){
            ll i = j;
            ll res = 1e8;
            
            while(i>=1){
                string temp = s.substr(i-1,j-i+1);
                
                unsigned long dece = stoi(temp,0,2);
                
                if(temp[0]!='0' && (15625 % dece) == 0){
                    res = min(res,dp[i-1]+1);
                }
                i--;
            }
            dp[j]=res;
        }
        
        if(dp[n]==1e8){
            return -1;
        }
        else{
            return (int)dp[n];
        }        
    }
};