class Solution {
    private:
    typedef int ll;
    const int mod = 1e9+7;
    int dp[200][201][201];

    ll solve(ll ind,vector<int>&nums,ll gcd1,ll gcd2){
        // base case 
        if(ind>=nums.size()){
            return (gcd1 && gcd2) && (gcd1==gcd2);
        }

        if(dp[ind][gcd1][gcd2]!=-1){
            return dp[ind][gcd1][gcd2];
        }

        ll skip = solve(ind+1,nums,gcd1,gcd2)%mod;
        ll firSeq = solve(ind+1,nums,__gcd(nums[ind],gcd1),gcd2)%mod;
        ll secSeq = solve(ind+1,nums,gcd1,__gcd(nums[ind],gcd2))%mod;

        return dp[ind][gcd1][gcd2]=(0LL+skip+firSeq+secSeq)%mod;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,0,0);
    }
};