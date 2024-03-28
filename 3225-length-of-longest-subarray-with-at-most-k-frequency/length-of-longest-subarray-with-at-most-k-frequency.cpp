class Solution {
public:
    typedef long long int ll;
    
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<ll,ll>um;
        
        ll i=0,j=0, n=nums.size();
        
        ll ans = 0;
        ll maxiOccur = 0;
        
        while(j<n){
            um[nums[j]]++;
            
            maxiOccur=max(maxiOccur,um[nums[j]]);
            
            if(maxiOccur<=k){
                ans = max(ans,j-i+1);
                j++;
            }
            else{
                while(maxiOccur>k && i<=j){
                    
                    if(maxiOccur == um[nums[i]]){
                        maxiOccur--;
                    }
                    
                    um[nums[i]]--;
                    i++;
                }
                j++;
            }
            
        }
        return ans;
    }
};