class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int maxi = 0;

        unordered_map<int,int>um;

        for(auto num : nums){
            um[num]++;maxi=max(maxi,um[num]);
        }

        vector<vector<int>> ans(maxi);

        for(auto it : um){
            for(int i=0;i<it.second;i++){
                ans[i].push_back(it.first);
            }
        }
        
        return ans;
    }
};