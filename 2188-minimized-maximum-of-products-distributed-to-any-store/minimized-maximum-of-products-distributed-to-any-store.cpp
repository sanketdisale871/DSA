class Solution {
    private:
typedef long long int ll;
   bool isPossible(ll mid,ll n,vector<int>&qnt){
    ll res = 0;

    for(auto it:qnt){
        if(it%mid==0){
            res+=it/mid;
        }
        else{
            res+=it/mid;
            res+=1;
        }
        // res+=ceil((qnt*1.0)/mid);
    }

    return res<=n;
   }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        ll low = 1;
        ll high = 1e5;

        ll ans = 0;

        while(low<=high){
            ll mid = low + (high-low)/2;

            if(isPossible(mid,n,quantities)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};