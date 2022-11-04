class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(int index,int target,vector<int>& arr, vector<int> &temp,int n){
        
        // Base case
        if(index==n){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        
        // Pick the same element
        if(arr[index]<=target){
            temp.push_back(arr[index]);
            
            solve(index,target-arr[index],arr,temp,n);
            // backtreking
            temp.pop_back();
        }
        
        // Un pick the element
        solve(index+1,target,arr,temp,n);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int index=0;
        int n = candidates.size();
        vector<int>temp;
        
        solve(index,target,candidates,temp,n);
        
        return ans;
    }
};
