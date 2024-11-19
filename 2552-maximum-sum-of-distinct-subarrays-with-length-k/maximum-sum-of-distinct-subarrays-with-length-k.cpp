class Solution {
public:
    typedef long long int ll;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll n = nums.size();

        ll i=0,j=0;
        ll maxiSum = 0;
        ll sum = 0;
        unordered_map<ll,ll>um;

        while(j<n){
            sum+=nums[j];
            um[nums[j]]++;

            if(j-i+1<k){
                j++;
            }
            else{
                // find answer 
                if(um.size()==k && sum>maxiSum){
                    maxiSum = sum;
                }
                // slide window
                um[nums[i]]--;
                if(um[nums[i]]==0){
                    um.erase(nums[i]);
                }
                sum-=nums[i];

                i++;
                j++;
            }
        }
        return maxiSum;
    }
};