class Solution {
public:
    typedef long long int ll;
    
    long long maxPairStrength(vector<int>& nums) {
        ll n = nums.size();

        ll ans = 0LL;

        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                ll t = __gcd(nums[i],nums[j]);
                 t*=t;
                ll r = (nums[i]*1ll*nums[j]) / t;

                ans = max(ans,r);
            }
        }
        return ans;
    }
};