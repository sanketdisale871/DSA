class Solution {
    private:
    int findSumbsetSum(vector<int>&nums,int res){
        int n = nums.size();

        vector<vector<int>>dp(n+1,vector<int>(abs(res)+1,0));

        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }

        dp[0][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=res;j++){
                dp[i][j]=dp[i-1][j];

                if(j>=nums[i-1]){
                    dp[i][j]+=dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][res];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum = accumulate(nums.begin(),nums.end(),0);

        totSum+=target;

        if(totSum%2!=0){
            return 0;
        }

        int res = totSum/2;

        if(res<0){
            return 0;
        }

        return findSumbsetSum(nums,res);
    }
};