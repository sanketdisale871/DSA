class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(int index,int n,vector<int>&nums){
        
        // Base condition
        if(index==n){
            ans.push_back(nums);
            return;
        }
        
        // 
        for(int i=index;i<n;i++){
            
            swap(nums[index],nums[i]);
            
            solve(index+1,n,nums);
            
            // backtreaking
            swap(nums[index],nums[i]);
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {

        int index = 0;
        int n = nums.size();
        
        solve(index,n,nums);
        
        return ans;
    }
};
