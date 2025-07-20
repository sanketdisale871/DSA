class Solution {
    public int climbStairs(int n) {
        // n Steps to reach the TOP 
        //climb 1 or 2 steps 
        // No.of Distinict ways, I can climb to TOP
        int[] dp = new int[n+1];
        dp[0]=1;dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
}