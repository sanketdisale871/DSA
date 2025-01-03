class Solution {
public:
    typedef long long int ll;
    int waysToSplitArray(vector<int>& nums) {
        ll n = nums.size();

        vector<ll>preSum(n+1,0);

        for(ll i=1;i<=n;i++){
            preSum[i]=preSum[i-1]+nums[i-1];
        }

        ll ans = 0;

        for(ll i=1;i<n;i++){
            ll lefSum = preSum[i];

            ll rigSum = preSum[n]-preSum[i];

            if(lefSum>=rigSum){
                ans++;
            }
        }


        return ans;
    }
};