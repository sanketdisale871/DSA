class Solution {
public:
    typedef long long int ll;
    int maxCoins(vector<int>& nums) {
        ll n = nums.size();

        vector<ll>arr;
        arr.push_back(1);
        for(auto it:nums){
            arr.push_back(it);
        }
        arr.push_back(1);

        // dp[i][j] => Maxi coints i get by removing the coins from [i.....j]
        vector<vector<ll>>dp(n+5,vector<ll>(n+5,0)); 

        for(ll i=1;i<=n;i++){
            dp[i][i]=arr[i-1]*arr[i]*arr[i+1];
        }

        ll len=2;
        while(len<=n){
            ll i=1;
            while(i<=(n-len+1)){
                ll j  =i+len-1;

                ll res = INT_MIN;

                ll k=i;
                while(k<=j){

                    ll temp = arr[i-1]*arr[k]*arr[j+1];

                    if(i!=k){
                        temp+=dp[i][k-1];
                    }

                    if(j!=k){
                        temp+=dp[k+1][j];
                    }

                    res = max(res,temp);
                    k++;
                }
                dp[i][j]=res;
                i++;
            }
            len++;
        }
        return dp[1][n];

    }
};