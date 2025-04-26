class Solution {
public:
    typedef long long int ll;
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll ans = 0;

        ll badi = -1,mini = -1,maxi = -1,n = nums.size();
        // badi => The Element outside the range minK and maxK 
        // mini => point the location of minK
        // maxi => point the location of maxK 

        for(ll i=0;i<n;i++){
            if(nums[i]<minK || nums[i]> maxK){
                badi=i;
            }

            if(nums[i]==minK) mini = i;
            if(nums[i]==maxK) maxi = i ;
            
            ll t = 0;
            ans+=max(t,min(mini,maxi)-badi);
        }
        return ans;
    }
};