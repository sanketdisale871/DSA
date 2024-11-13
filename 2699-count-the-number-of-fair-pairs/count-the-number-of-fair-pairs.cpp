class Solution {
    private:
    typedef long long int ll;

    ll findGtreEql(ll low,ll high,ll val1,vector<int>&nums){
        ll ans = -1;
        while(low<=high){
            ll mid = low + (high-low)/2;

            if(nums[mid]>=val1){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }

    ll findLwrEql(ll low,ll high,ll val,vector<int>&nums){
        ll ans = -1;

        while(low<=high){
            ll mid = low + (high-low)/2;

            if(nums[mid]<=val){
                ans = mid;
                low = mid+1;
            }
            else{
                high  =mid-1;
            }
        }
        return ans;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ll ans = 0;

        sort(nums.begin(),nums.end());

        ll n = nums.size();


        for(ll i=0;i<n;i++){
            ll val1 = lower-nums[i];
            ll s1 = findGtreEql(0,i-1,val1,nums);
            if(s1==-1){
                continue;
            }
            ll val2 = upper-nums[i];
            ll s2 = findLwrEql(s1,i-1,val2,nums);

            if(s2<s1){
                continue;
            }

            int prs = s2-s1+1;

            ans+=prs;
        }


        return ans;
    }
};