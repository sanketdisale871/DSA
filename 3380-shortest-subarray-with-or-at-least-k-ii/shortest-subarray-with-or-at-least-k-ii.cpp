class Solution {
    private:
    typedef long long int ll;
    
    bool isPossible(ll len,vector<vector<ll>> &preSetBits,ll k){
        ll n = preSetBits.size();

        for(ll i=1;i<n-len;i++){
            ll j = i+len;

            ll res = 0;

            for(ll bit=0;bit<32;bit++){
                ll r = preSetBits[j][bit]-preSetBits[i-1][bit];

                if(r>0){
                    res = res | (1<<bit);
                }
            }

            if(res>=k){
                return true;
            }
        }
        return false;
        
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<vector<ll>>preSetBits(n+1,vector<ll>(32,0));


        for(ll i=0;i<n;i++){
            for(ll bit=0;bit<32;bit++){
                if(nums[i] & (1<<bit)){
                    preSetBits[i+1][bit]=1+preSetBits[i][bit];
                }
                else{
                    preSetBits[i+1][bit] = preSetBits[i][bit];
                }
// 
                // cout<<" i : "<<i<<" bit : "<<bit<<" "<<preSetBits[i+1][bit]<<endl;
            }
        }

        ll low = 0;
        ll high = n;

        ll ans = -1;
        while(low<=high){
            ll mid = low + (high-low)/2;

            ll r = isPossible(mid,preSetBits,k);

            // cout<<" mid : "<<mid<<" r : "<<r<<endl;

            if(r){
                ans = mid+1;
                high =mid-1;
            }
            else{
                low = mid+1;
            }


        }
        return ans;

    }
};