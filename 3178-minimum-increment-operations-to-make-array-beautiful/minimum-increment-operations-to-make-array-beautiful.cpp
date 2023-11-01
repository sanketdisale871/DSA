class Solution {
    vector<vector<long long>>dp;
    long long minCost(int ind,vector<int>&nums,int skip,int k){
        // Base case
        if(ind == nums.size()){
            return 0;
        }

        if(dp[ind][skip]!=-1){
            return dp[ind][skip];
        }

        long long  take = max(0,k-nums[ind])+minCost(ind+1,nums,3,k);

        long long  nonTake = 1e18;

        if(skip>1){
            nonTake = minCost(ind+1,nums,skip-1,k);
        }

        return dp[ind][skip]=min(take,nonTake);
    }
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        dp.assign(n,vector<long long>(4,-1));
        return minCost(0,nums,3,k);
    }
};