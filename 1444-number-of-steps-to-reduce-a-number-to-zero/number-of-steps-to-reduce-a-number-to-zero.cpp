class Solution {
public:
    int numberOfSteps(int num) {
        vector<int>dp(num+1,0);
        dp[0]=0;

        for(int i=1;i<=num;i++){
            if(i%2==0){
                dp[i]=1+dp[i/2];
            }
            else{
                dp[i]=1+dp[i-1];
            }
            
            // cout<<"i: "<<i<<" dp[i] : "<<dp[i]<<endl;
        }
        return dp[num];
    }
};