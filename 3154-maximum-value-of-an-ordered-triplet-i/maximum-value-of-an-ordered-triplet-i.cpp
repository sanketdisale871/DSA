class Solution {
public:
    typedef long long int ll;
    long long maximumTripletValue(vector<int>& nums) {
        ll n = nums.size();

        vector<int>pref(n+1,0);
        vector<int>suff(n+1,0);

        // Prefix Maximum Cnt
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1],nums[i]);
        } 

        // Suffix Maximum number cnt 
        suff[n-1]=nums[n-1];
        for(int j=n-2;j>=0;j--){
            suff[j]=max(suff[j+1],nums[j]);
        }
        // do the our calculation
        ll ans = 0;

        for(int i=1;i<n-1;i++){
            ll res = (pref[i-1]-nums[i])*1ll*suff[i+1];
            ans = max(ans,res);
        }
        return ans;

    }
};