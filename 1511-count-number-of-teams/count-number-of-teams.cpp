class Solution {
public:
    typedef long long int ll;
    int numTeams(vector<int>& arr) {
        ll n = arr.size();

        ll ans = 0;

        for(ll i=0;i<n;i++){
            ll smLef = 0,bgLef=0;
            ll smRig = 0,bgRig = 0;

            for(ll j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    bgRig++;
                }
                else if(arr[j]<arr[i]){
                    smRig++;
                }
            }

            for(ll j=i-1;j>=0;j--){
                if(arr[j]>arr[i]){
                    bgLef++;
                }
                else if(arr[j]<arr[i]){
                    smLef++;
                }
            }

            ll res = bgLef*smRig + smLef*bgRig;
            ans+=res;
        }
        // return ans;

        return ans;
    }
};