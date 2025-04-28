class Solution {
    private:
    typedef long long int ll;
    ll atMost(vector<int>&nums,ll k){
        ll i=0,j=0;
        ll n = nums.size();

        ll cntSub = 0;

        ll sc = 0;

        while(j<n){
            sc+=nums[j];

            if(sc*(j-i+1)<=k){
                cntSub+=(j-i+1);
                j++;
            }
            else{
                while(i<=j && sc*(j-i+1)>k){
                    sc-=nums[i];
                    i++;
                }
                cntSub+=(j-i+1);
                j++;
            }
        }
        return cntSub;
    }
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        return atMost(nums,k-1);
    }
};