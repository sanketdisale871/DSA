class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n = arr.size();

        vector<int>dp(n,1);

        vector<int>dp1(n,1);

        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(arr[j]<arr[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[i]){
                    dp1[i]=max(dp1[i],1+dp1[j]);
                }
            }
        }

        int res = INT_MAX;

        for(int i=1;i<n-1;i++){
            if(dp[i]>1 && dp1[i]>1){

            int t = dp[i]+dp1[i]-1;
            if(t>=3){

            int r = n-t;
            res = min(res,r);
            }
            }
        }
        return res;
    }
};