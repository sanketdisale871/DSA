class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0,j=0;
        int maxiOccur = 0; 
        unordered_map<int,int>um;
        int ans = 0;
        
        
        while(j<n){
            um[nums[j]]++;
            
            maxiOccur = max(maxiOccur,um[nums[j]]);

            if((j-i+1)-maxiOccur <=k){
                ans = max(ans,maxiOccur);
                j++;                    
            }
            else{
                while((j-i+1)-maxiOccur > k && i<=j){
                    

                    um[nums[i]]--;
                    i++;
                }
                j++;
            }  
        }
        return ans;
    }
};