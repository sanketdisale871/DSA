class Solution {
public:
    typedef long long int ll;
    int maximumLength(vector<int>& nums) {
        ll ans = 1;

        unordered_map<ll,ll>um;
        for(auto num:nums){
            um[num]++;
        }

        // [1,1,1,1,1,1,1,1,2,4,8,16,32] => 7 (Length)
       if(um.count(1)){
           if(um[1]%2==0){
               ans = um[1]-1;
           }
           else{
               ans = um[1];
           }
       }

        for(auto num : nums){
            ll cnt = 0;
            ll val = num;
            while(val<=1e9 && um.count(val) &&um[val]>=2 && val!=1){
                cnt+=2;
                val*=val;
            }

            if(um[val]==1){
                cnt++;
            }
            else{
                cnt--;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};