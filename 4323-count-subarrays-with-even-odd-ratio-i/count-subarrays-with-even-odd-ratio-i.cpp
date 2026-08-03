class Solution {
public:
    typedef long long int ll;
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        ll ans = 0LL;

        for(ll i=0;i<n;i++){
            ll oddElem = 0;
            ll evenElem = 0;

            for(ll j=i;j<n;j++){
                if(nums[j]&1){
                    oddElem++;
                }
                else{
                    evenElem++;
                }

                if(oddElem>0){
                    if(evenElem * 1LL * b <= oddElem * 1LL * a){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};