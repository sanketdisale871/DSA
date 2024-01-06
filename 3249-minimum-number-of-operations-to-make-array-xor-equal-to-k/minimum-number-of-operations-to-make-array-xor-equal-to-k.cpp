class Solution {
public:
typedef long long int ll;
    int minOperations(vector<int>& nums, int k) {
        ll n = nums.size();
        ll ans = 0;
        ll xOr = 0;

        for(auto it:nums){
            xOr^=it;
        }

        for(ll bit = 0;bit<31;bit++){
            ll bitNo = (1<<bit);

            if((xOr&bitNo) != (k&bitNo)){
                ans++;
            }
        }

        return (int)ans;
    }

};