class Solution {
public:
    typedef long long int ll;
    long long minEnd(int n, int x) {
        string b = bitset<32>(x).to_string();
               b =  "000000000000000000000000000000000000"+b;

        string binNMO = bitset<32>(n-1).to_string();

        ll j = binNMO.size()-1;

        for(ll i = b.size()-1;i>=0 && j>=0;i--){

            if(b[i]=='0'){
                b[i]=binNMO[j];
                j--;
            }

        }

        cout<<b<<endl;

        ll ans = 0;


        ll bit = 0;
        ll res = 1;
        for(ll i=b.size()-1;i>=0 && bit<=50;i--){
            if(b[i]=='1'){
                ans = ans + res;
            }
            bit++;
           res = 2*res;
        }
        return ans;
    }
};