class Solution {
    public:
    vector<vector<int>>ans;
    void genAllSubsets(int ind,vector<int>&nums,vector<int>temp){
        // base case 
        if(ind>=nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        genAllSubsets(ind+1,nums,temp);
        temp.pop_back();

        genAllSubsets(ind+1,nums,temp);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        
        genAllSubsets(0,nums,temp);

        return ans;
    }
};