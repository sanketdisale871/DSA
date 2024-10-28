class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int maxElem = *max_element(nums.begin(),nums.end());

        vector<int>dp(maxElem+1,0);

        int maxiSeq = 0;

        for(int i=0;i<n;i++){
            int swRt = sqrt(nums[i]);

            if(swRt*swRt == nums[i]){
                dp[nums[i]]=1+dp[swRt];
            }
            else{
                dp[nums[i]]=1;
            }

            maxiSeq = max(maxiSeq,dp[nums[i]]);
        }

        return maxiSeq==1?-1:maxiSeq;
    }
};