class Solution {
    private:

    void solve(int ind,int sum,int k,vector<int>&temp,vector<int>&nums,vector<vector<int>>&ans){
        // Base case
        if(ind >= nums.size() || temp.size()==k){
            if(sum==0 && temp.size()==k){
                ans.push_back(temp);
            }
            return;
        }

        

            if(nums[ind]<=sum){
                // put into ds 
                temp.push_back(nums[ind]);
                solve(ind+1,sum-nums[ind],k,temp,nums,ans);
                temp.pop_back();

                // not put into ds 
                solve(ind+1,sum,k,temp,nums,ans);
            }          
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;

        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        vector<int>temp;

        solve(0,n,k,temp,nums,ans);


        return ans;
    }
};