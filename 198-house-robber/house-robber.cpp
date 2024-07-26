class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp0(n,0);
        vector<int>dp1(n,0);

        dp0[0]=0;
        dp1[0]=nums[0];

        if(n>1){
            dp0[1]=max(dp0[0],dp1[0]);
            dp1[1]=nums[1]+dp0[0];
        }

        for(int i=2;i<n;i++){
            dp0[i]=max(dp0[i-1],dp1[i-1]);
            dp1[i]=nums[i]+max(dp0[i-1],dp1[i-2]);
        }
        return max(dp0[n-1],dp1[n-1]);
    }
};