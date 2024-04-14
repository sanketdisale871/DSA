class Solution {
    private:
    typedef long long int ll;

    ll findCnt(ll mid,vector<int>&coins){
        ll n = coins.size();

        ll cnt = 0;

        for(ll mask = 1;mask<(1<<n);mask++){
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
    int nthUglyNumber(int n, int a, int b, int c) {
        vector<int>coins;

        coins.push_back(a);
        coins.push_back(b);
        coins.push_back(c);

        ll ans = 0;

        ll low = 0;
        ll high = 1e11;

        while(low<=high){
            ll mid = (low+high)/2;

            ll cnt = findCnt(mid,coins);

            if(cnt>=n){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};