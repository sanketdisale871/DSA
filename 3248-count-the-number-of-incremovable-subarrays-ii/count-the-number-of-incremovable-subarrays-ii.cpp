class Solution {
public:
    typedef long long int ll;
    long long incremovableSubarrayCount(vector<int>& nums) {
        ll n = nums.size();

        ll leftInd = 0,rightInd = n-1;

        while(leftInd<n-1 && nums[leftInd]<nums[leftInd+1]){
            leftInd++;
        }

        while(rightInd>0 && nums[rightInd] >nums[rightInd-1]){
            rightInd--;
        }

        if(leftInd == n-1){
            return n*(n+1)/2;
        }

        ll ans = n-rightInd+1;

        for(ll i=0;i<=leftInd;i++){
            ll uppInd = upper_bound(nums.begin()+rightInd,nums.end(),nums[i])-nums.begin();

            ans+=(n-uppInd+1);
        }
        return ans;


    }
};