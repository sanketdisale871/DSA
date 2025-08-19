class Solution {
public:
    typedef long long int ll;
    long long zeroFilledSubarray(vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0;

        int cnt1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt1++;
            }
            if(cnt1>0 && nums[i]!=0){
                ll arrs = cnt1*1ll*(cnt1*1ll+1)/2;
                ans+=arrs;
                cnt1=0;
            }
        }

        if(cnt1>0){
             ll arrs = cnt1*1ll*(cnt1*1ll+1)/2;
            ans+=arrs;
        }


        return ans;
    }
};