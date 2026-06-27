class Solution {
public:
    typedef long long int ll;
    int maximumLength(vector<int>& nums) {
        unordered_map<ll,ll>um;

        ll ans = 1;
        // Whatever the frequency,here I'm attaching it.
        for(auto it:nums){
            um[it]++;
        }

        if(um.count(1)){
            if(um[1]%2==0){
                ans = um[1]-1;
            }
            else{
                ans = um[1];
            }
        }

        for(auto num:nums){
            ll val = num;
            ll cnt = 0;

            while(val<=1e9 && um[val]>=2 && val!=1){
                cnt+=2;
                val = val*val;
            }

            if(um[val]==1){
                cnt++;
            }
            else{
                cnt--;
            }
            ans = max(ans,cnt);
        }
        return (int)ans;
    }
};