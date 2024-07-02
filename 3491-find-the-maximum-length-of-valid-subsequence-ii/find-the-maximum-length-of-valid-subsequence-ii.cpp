class Solution {
public:
    typedef long long int ll;
    int maximumLength(vector<int>& nums, int k) {
        for(auto &it:nums){
            it%=k;
        }
        ll n = nums.size();

        vector<ll>lst(k,-1);
        vector<vector<ll>>dp(n,vector<ll>(k,0));
        ll ans = 0;

        for(ll i=0;i<n;i++){
            for(ll val=0;val<k;val++){
                if(lst[val]==-1){
                    dp[i][val]=1;
                }
                else{
                    dp[i][val]= dp[ lst[val] ][ nums[i] ]+1;
                }
                ans = max(ans,dp[i][val]);
            }
            lst[nums[i]]=i;
        }

        return ans;        
    }
};