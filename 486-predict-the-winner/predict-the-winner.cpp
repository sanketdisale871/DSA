class Solution {
    private:
    typedef long long int ll;
    vector<vector<ll>>dp;
    ll findPla1Score(ll i,ll j,vector<int>&nums){
        // base case
        if(i>j){
            return 0;
        }

        if(i==j){
            return dp[i][j]=nums[i];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        ll startPickUp = nums[i]+min(findPla1Score(i+2,j,nums),findPla1Score(i+1,j-1,nums));

        ll endPickUp = nums[j]+min(findPla1Score(i+1,j-1,nums),findPla1Score(i,j-2,nums));

        return dp[i][j]=max(startPickUp,endPickUp);
    }
public:
    bool predictTheWinner(vector<int>& nums) {

        dp.resize(21,vector<ll>(21,-1));

        ll fPlayScore = findPla1Score(0,nums.size()-1,nums);

        ll sPlayScore = accumulate(nums.begin(),nums.end(),0)-fPlayScore;

        if(fPlayScore>=sPlayScore){
            return true;
        }
        return false;
    }
};