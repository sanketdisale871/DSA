class Solution {
public:
    typedef long long int ll;
    int maxCoins(vector<int>& arr) {
        ll n = arr.size();

        vector<int>nums;
        nums.push_back(1);
        // For avoiding Runtime Errors, making given arrays as 1 based indexing 
        for(auto it:arr){
            nums.push_back(it);
        }
        nums.push_back(1);

        vector<vector<ll>>dp(n+1,vector<ll>(n+1));
        // dp[i][j] => Best answer from [i.........j]

        // Length = 1 
        for(ll i=1;i<=n;i++){
            dp[i][i]=nums[i-1]*nums[i]*nums[i+1];
        }

        // Length 2 and above 
        ll len = 2;
        while(len<=n){
            ll i=1;
            while(i<=(n-len+1)){
                ll j = i+len-1;
                ll maxi = INT_MIN;
                ll k = i; // k -> Burst this balloon at last 
                while(k<=j){

                    ll res = nums[i-1]*nums[k]*nums[j+1];

                    if(i!=k){
                        res+=dp[i][k-1] ;
                    }

                    if(j!=k){
                        res+=dp[k+1][j];
                    }

                    maxi = max(maxi,res);
                    k++;
                }
                dp[i][j]=maxi; 
                i++;               
            }
            len++;
        }
        return dp[1][n];
    }
};