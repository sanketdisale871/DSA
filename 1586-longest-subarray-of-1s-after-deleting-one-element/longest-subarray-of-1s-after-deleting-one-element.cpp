class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int>prefOne(n+1,0);
        vector<int>suffOne(n+1,0);

        if(nums[0]==1){
            prefOne[0]=1;
        }

        for(int i=1;i<n;i++){
            if(nums[i]==1){
                prefOne[i]+=1+prefOne[i-1];
            }
            else{
                prefOne[i]=0;
            }
        }

        if(nums[n-1]==1){
            suffOne[n-1]=1;
        }

        for(int i=n-2;i>=0;i--){
            if(nums[i]==1){
                suffOne[i]+=1+suffOne[i+1];
            }
            else{
                suffOne[i] =0;   
            }
        }
        
        int ans = 0;

        if(n>1){
            ans = max(prefOne[n-2],suffOne[1]);
        }

        for(int i=1;i<n-1;i++){
            int res = prefOne[i-1] + suffOne[i+1];
            ans = max(ans,res);
        }        

        return ans;
    }
};