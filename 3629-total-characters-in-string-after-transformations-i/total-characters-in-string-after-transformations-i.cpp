class Solution {
public:
typedef long long int ll;
const int mod = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<ll>occur(26,0);

        for(auto ch:s){
            occur[ch-'a']++;
        }

        while(t--){
            vector<ll>temp(26,0);

            for(ll i=0;i<25;i++){
                temp[i+1]=occur[i]%mod;
            }

            temp[0]+=occur[25];
            temp[0]%=mod;
            temp[1]+=occur[25];
            temp[1]%=mod;

            occur = temp;
        }
    ll tt = 0;
        ll totLen = accumulate(occur.begin(),occur.end(),tt);
        return totLen%mod;
    }
};