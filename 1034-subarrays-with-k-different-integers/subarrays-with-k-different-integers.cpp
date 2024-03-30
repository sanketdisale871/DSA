class Solution {
    private:
    typedef long long int ll;

    ll findAtMost(vector<int>&nums,int k){
        ll ans = 0;
        unordered_map<ll,ll>um;
        ll i=0,j=0;
        ll n = nums.size();

        while(j<n){
            um[nums[j]]++;

            if(um.size()<=k){
                ans+=(j-i+1);
                j++;
            }
            else{
                while(um.size()>k && i<=j){
                    um[nums[i]]--;

                    if(um[nums[i]]==0){
                        um.erase(nums[i]);
                    }
                    i++;
                }
                ans+=(j-i+1);
                j++;
            }
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return findAtMost(nums,k)-findAtMost(nums,k-1);
    }
};