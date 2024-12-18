class Solution {
    private:
    typedef long long int ll;

    ll atMost(vector<int>&nums,ll k){
        ll i =0,j=0;
        ll n = nums.size();
        ll ans = 0;

        ll prod = 1;

        while(j<n){
            prod*=nums[j];

            if(prod<=k){
                ans+=(j-i+1);
                j++;
            }
            else{
                while(i<=j && prod>k){
                    prod/=nums[i];
                    i++;
                }
                ans+=(j-i+1);
                j++;
            }
        }
        return ans;
    }
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        return atMost(nums,k-1);
    }
};