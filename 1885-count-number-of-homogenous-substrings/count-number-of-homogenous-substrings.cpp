class Solution {
public:
typedef long long int ll;
    int countHomogenous(string s) {
        const int mod = 1e9+7;
        ll ans = 0;
        char prev = '-1';
        ll cnt = 0;
        ll n = s.length();

        for(ll i=0;i<n;i++){
            if(s[i]==prev){
                cnt++;
            }
            else{
                cnt = 1;
                prev = s[i];
            }
            ans =(ans+cnt)%mod;
        }
        return (int)ans;
    }
};