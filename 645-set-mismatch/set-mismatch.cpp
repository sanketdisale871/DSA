class Solution {
public:
    typedef long long int ll;
    vector<int> findErrorNums(vector<int>& nums) {
        ll n = nums.size();
        // x => Missing, y = duplicate
        // Sn-S = Repeating , x--y = val1 
        ll sum = 0;
        ll sum1 = 0;
        for(auto num:nums){
            sum+=num;
            sum1+=(num*1ll*num);
        }

        ll sn = n*1ll*(n+1)/2;
        ll val1 = sn-sum; // x-y = val1 

        ll sn2 = n*(n+1)*(2*n+1)/6;

        ll val2 = sn2-sum1;

        ll val3 = val2/val1;

        ll x = (val1+val3)/2;
        ll y = val3-x;

        return {(int)y,(int)x};

        

    }
};