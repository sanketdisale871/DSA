class Solution {
public:
    typedef long long int ll;
    int countTriplets(vector<int>& arr) {
        ll ans = 0;

        ll n = arr.size();

        for(ll i=0;i<n;i++){
            ll preXor = 0;
            for(ll j=i;j<n;j++){
                preXor^=arr[j];
                ll t = 0;
                for(ll k=j+1;k<n;k++){
                    t^=arr[k];

                    if(preXor==t){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};