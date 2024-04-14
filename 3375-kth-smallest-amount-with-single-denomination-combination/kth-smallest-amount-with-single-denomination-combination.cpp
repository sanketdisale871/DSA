class Solution {
    private:
    typedef long long int ll;
    ll findCnt(ll mid,vector<int>&coins){
        ll cnt = 0;
        ll n = coins.size();

        for(ll mask=1;mask<(1<<n);mask++){
            ll t = 1;
            for(ll i=0;i<n;i++){
                if(mask & (1<<i)){
                    t = lcm(t,coins[i]);
                }
            }

            if(__builtin_popcount(mask) & 1){
                cnt+=(mid/t);
            }
            else{
                cnt-=(mid/t);
            }
        }
        return cnt;
    }
public:
    
    long long findKthSmallest(vector<int>& coins, int k) {
        ll ans  = 0;

        ll low = 0;
        ll high = 1e12;

        while(low<=high){
            ll mid = (low+high)/2;

            ll cnt = findCnt(mid,coins);

            if(cnt>=k){
                ans = mid;
                high= mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};