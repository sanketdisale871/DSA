class Solution {
    private:
    typedef long long int ll;

    ll cntAtMost(vector<int>& nums, int k){
        ll ans = 0;

        ll oddNums = 0;
        ll i=0,j=0,n = nums.size();

        while(j<n){
            if(nums[j]&1){
                oddNums++;
            }

            if(oddNums<=k){
                ans+=(j-i+1);
                j++;
            }
            else{
                while((oddNums>k) && i<=j){
                    if(nums[i]&1){
                        oddNums--;
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        ll res = cntAtMost(nums,k)-cntAtMost(nums,k-1);

        return (int)res;
    }
};