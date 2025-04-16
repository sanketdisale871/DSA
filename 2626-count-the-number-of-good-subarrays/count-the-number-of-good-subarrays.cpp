class Solution {
    private:
    typedef long long int ll;

    ll findSubarrays(vector<int>& nums,int k){
        ll subarrayCnt = 0;

        unordered_map<ll,ll>um;

        ll prs = 0;
        ll i=0,j=0;

        ll n = nums.size();

        while(j<n){
            prs+=um[nums[j]];
            um[nums[j]]++;

            if(prs<k){
                j++;
            }
            else{
                while(i<=j && prs>=k){
                    cout<<"i "<<i<<" j "<<j<<endl;
                    subarrayCnt+=(n-j);

                    um[nums[i]]--;
                    prs-=um[nums[i]];
                    i++;
                }
                j++;
            }
        }
        return subarrayCnt;
    }
public:
    long long countGood(vector<int>& nums, int k) {
        return findSubarrays(nums,k);
    }
};