class Solution {
    private:
    typedef long long int ll;

    ll findSubar(vector<int>&nums,int k,ll num){
        ll ans = 0;
        ll n = nums.size();
        ll i=0,j=0;

        ll occur = 0;

        while(j<n){
            if(nums[j]==num){
                occur++;
            }

            if(occur<k){
                j++;
            }
            else{
                while(occur>=k && i<=j){
                    ans+=(n-j);

                    if(nums[i]==num){
                        occur--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll maxiElem = *max_element(nums.begin(),nums.end());

        return findSubar(nums,k,maxiElem);
    }
};