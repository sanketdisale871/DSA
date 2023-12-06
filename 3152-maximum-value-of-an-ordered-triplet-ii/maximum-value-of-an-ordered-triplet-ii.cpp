class Solution {

public:
typedef long long int ll;
    long long maximumTripletValue(vector<int>& nums) {
        
        int n = nums.size();

        ll ans =0;

        vector<ll>prefix(n,0);
        vector<ll>suffix(n,0);

        int maxi = nums[0];

        for(ll i=1;i<n;i++){
            prefix[i]=maxi;

            maxi = max(maxi,nums[i]);
        }

        maxi = nums[n-1];

        for(ll i=n-2;i>=0;i--){
            suffix[i]=maxi;
            maxi = max(maxi,nums[i]);
        }

        for(ll i=1;i<n-1;i++){
            ll res = (prefix[i]-nums[i])*suffix[i];

            ans = max(ans,res);
        }

        return ans;
    }
};