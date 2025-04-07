class Solution {
    private:
    vector<vector<int>>dp;
    bool checkIsItPresent(int ind,vector<int>&nums,int sum){
        if(ind>=nums.size()){
            if(sum==0){
                return true;
            }
            return false;
        }

        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }

        // taking opton 
        if(nums[ind]<=sum){
            return dp[ind][sum]=checkIsItPresent(ind+1,nums,sum-nums[ind])||checkIsItPresent(ind+1,nums,sum);
        }
        else{
            return dp[ind][sum]=checkIsItPresent(ind+1,nums,sum);
        }
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totSum = accumulate(nums.begin(),nums.end(),0);

        if(totSum%2!=0){
            return false;
        }

        dp.resize(n+2,vector<int>((totSum/2)+1,-1));

        return checkIsItPresent(0,nums,totSum/2);
    }
};