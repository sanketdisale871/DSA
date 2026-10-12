class Solution {
public:
    const int mod = 1e9+7;
    typedef long long int ll;
    int maxSum(vector<int>& nums, int k) {
        // Sum of squares of that elements 
        // AND Is descrement operator.
        // OR Is Increment operator.
        vector<int>setBits(32,0);
        ll ans = 0LL;

        for(auto num:nums){
            for(int bit=0;bit<32;bit++){
                if(num & (1<<bit)){
                    setBits[bit]++;
                }
            }
        }

        while(k--){
            ll x = 0ll;

            for(int i=0;i<32;i++){
                if(setBits[i]>0){
                    x = (x|(1<<i));
                    setBits[i]--;
                }
            }

            ll t = (x*1ll*x)%mod;
            ans+=t;
            ans%=mod;
        }
        return ans;
    }

};