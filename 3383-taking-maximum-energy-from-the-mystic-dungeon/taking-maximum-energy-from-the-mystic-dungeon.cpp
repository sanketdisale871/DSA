class Solution {
public:
    int maximumEnergy(vector<int>& en, int k) {
            int enSize = en.size();
            int maxiEn = INT_MIN;
            vector<int>dp(enSize,0);

            for(int i=0;i<k;i++){
                dp[i]=en[i];
                 if(i+k>=enSize){
                    maxiEn = max(maxiEn,dp[i]);
                }
            }

            for(int i=k;i<enSize;i++){
                dp[i]=max(en[i],en[i]+dp[i-k]);
                if(i+k>=enSize){
                    maxiEn = max(maxiEn,dp[i]);
                }
            }
            

            return maxiEn;

    }
};