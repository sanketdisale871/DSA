class Solution {
public:
    typedef long long int ll;
    long long findMaximumScore(vector<int>& nums) {
        ll ans = 0;
        ll maxiNum = INT_MIN;
        ll cnt = 0;

        ll i=0,j=0;
        ll n = nums.size();

        while(j<n){
            if(nums[j]<=nums[i]){
                j++;
            }
            else{
                ans+=(j-i)*nums[i];
                i=j;
                j++;
            }
        }

        if(i!=n-1){
            ans+=(j-i-1)*nums[i];
        }
        return ans;
    }
};