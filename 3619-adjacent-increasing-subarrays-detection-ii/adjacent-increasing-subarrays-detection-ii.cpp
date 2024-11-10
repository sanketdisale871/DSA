class Solution {
    private:
     bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>dp(n+1,0);

        dp[1]=1;

        for(int i=2;i<=n;i++){
            if(nums[i-1]>nums[i-2]){
                dp[i]=1+dp[i-1];
            }
            else{
                dp[i]=1;
            }


            if(i-k>=1){
                if(dp[i]>=k && dp[i-k]>=k){
                    return true;
                }
            }
        }
        return false;
    }
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n;
        int ans = 0;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(hasIncreasingSubarrays(nums,mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};