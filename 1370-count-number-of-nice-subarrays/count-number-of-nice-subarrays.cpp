class Solution {
    private:
    typedef long long int ll;

    ll countAtMost(vector<int>&nums,int k){
        ll i=0,j=0,n = nums.size();
        ll ans = 0;

        ll currOdd = 0;

        while(j<n){
            if((nums[j]&1)){
                currOdd++;
            }

            if(currOdd<=k){
                ans+=(j-i+1);
                j++;
            }
            else{
                while(currOdd>k && i<=j){
                    if((nums[i]&1)){
                        currOdd--;
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
        return countAtMost(nums,k)-countAtMost(nums,k-1);
    }
};