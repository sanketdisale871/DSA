class Solution {
public:
    typedef long long int ll;
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<ll,ll>um;
        ll cnt=0;
        ll ans = 0;
        um[0]=1;

        for(auto it:nums){
            if(it%modulo == k){
                cnt++;
            }

            ll r = (cnt+modulo-k)%modulo;
            ans+=um[r];
            um[cnt%modulo]++;
        }
        return ans;
    }
};