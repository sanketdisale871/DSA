class Solution {
public:
    typedef long long int ll;
    int countKConstraintSubstrings(string s, int k) {
        ll ans = 0;

        for(ll i=0;i<s.length();i++){
            ll z=0,o=0;
            for(ll j=i;j<s.length();j++){
                if(s[j]=='0'){
                    z++;
                }
                else{
                    o++;
                }

                if(z<=k || o<=k){
                    // cout<<"i "<<i<<" j :"<<j<<endl;
                    ans++;
                }
                else{
                    break;
                }
                
            }
        }


        return (int)ans;
    }
};