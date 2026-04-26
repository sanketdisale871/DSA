class Solution {
public:
    typedef long long int ll;
    long long minOperations(vector<int>& nums) {
        ll ans = 0;

        for(ll i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                ll t= 0;
                ll r = max(t,(nums[i]-nums[i+1])*1ll);
                ans+=r;
            }
        }
        return ans;
    }
};