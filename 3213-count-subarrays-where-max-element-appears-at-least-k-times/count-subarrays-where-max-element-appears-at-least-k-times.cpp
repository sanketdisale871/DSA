class Solution {
    private:
    typedef long long int ll;

public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll maxiElem = *max_element(nums.begin(),nums.end());
        ll n = nums.size();
        int occur = 0;
        ll ans = 0;

        ll i=0,j=0;

        while(j<n){
            if(nums[j]==maxiElem){
                occur++;
            }

            if(occur<k){
                j++;
            }
            else{
                while(i<=j && occur>=k){
                    ans+=(n-j);
                    if(nums[i]==maxiElem){
                        occur--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};