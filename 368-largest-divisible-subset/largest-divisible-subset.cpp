class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        vector<int>dp(n+1,1);
        vector<int>par(n+1,0);

        for(int i=0;i<n;i++){
            par[i]=i;
        }

        int maxiLen = 1;
        int stInd = 0;

        for(int i=1;i<n;i++){
            int j = i-1;
            while(j>=0){
                if(nums[i]%nums[j]==0 && dp[i]< 1+dp[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                    par[i]=j;
                    if(maxiLen<dp[i]){
                        maxiLen = dp[i];
                        stInd = i;
                    }
                }
                j--;
            }           
        }
        vector<int>ans;

        while(stInd!=par[stInd]){
            ans.push_back(nums[stInd]);
            stInd = par[stInd];
        }

        ans.push_back(nums[stInd]);


        return ans;
    }
};