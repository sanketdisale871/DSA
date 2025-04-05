class Solution {
    private:
  
    vector<vector<int>>dp;
    int calculateSubsetsXOR(int currXor,vector<int>&nums,int ind){
        // Base case
        if(ind>=nums.size()){
            return currXor;
        }

        if(dp[ind][currXor]!=-1){
            return dp[ind][currXor];
        }

        int takingCurrElem = calculateSubsetsXOR(currXor^nums[ind],nums,ind+1);
        int nonTakingCurrElem = calculateSubsetsXOR(currXor,nums,ind+1);

        return dp[ind][currXor]=takingCurrElem+nonTakingCurrElem;
        
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        dp.resize(n+2,vector<int>(1e5,-1));
        
        int currXor = 0;

        return calculateSubsetsXOR(currXor,nums,0);
    }
};