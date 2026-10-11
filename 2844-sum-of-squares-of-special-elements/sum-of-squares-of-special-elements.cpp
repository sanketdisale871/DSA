class Solution {
private:
typedef long long int ll;
public:

    int sumOfSquares(vector<int>& nums) {
        ll ans = 0;

        ll n = nums.size();
        
        for(int i=1;i<=n;i++){
            if(n%i==0){
                ll res = nums[i-1]*1ll*nums[i-1];
                ans+=res;
            }
        }
        return (int)ans;
    }
};