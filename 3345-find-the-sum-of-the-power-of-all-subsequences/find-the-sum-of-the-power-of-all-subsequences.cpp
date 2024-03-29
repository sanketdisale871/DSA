class Solution {
public:
    typedef long long int ll;
    const int mod = 1e9+7;

    ll dp[101][101];

    ll power(ll x, ll y)
    {
        if (y == 0)
            return 1;
    
        ll temp = power(x, y / 2);
        if (y % 2 == 0)
            return (temp * temp)%mod;
        else
            return (x * temp * temp)%mod;
    }

    ll findSub(ll ind,ll n,ll sum,ll k,vector<int>&nums){
        // base case
        if(sum==k){
            ll t = (n-ind)%mod; // leftChars
            ll p = 2;
            return power(p,t)%mod;
        }

        if(sum>k || ind>=n){
            return 0;
        }

        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }

        ll tk = findSub(ind+1,n,sum+nums[ind],k,nums)%mod;
        ll ntk = 2*findSub(ind+1,n,sum,k,nums)%mod;


        return dp[ind][sum]=(tk+ntk)%mod;
    }

    int sumOfPower(vector<int>& nums, int k) {
        
        for(ll i=0;i<101;i++){
          
                for(ll k=0;k<101;k++){
                    dp[i][k]=-1;
                }
            
        }
        return findSub(0,nums.size(),0,k,nums);
    }
};