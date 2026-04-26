class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int>ans;

        ans.push_back(nums[0]);

        int lefFarMax = nums[0];

        for(int i=1;i<nums.size();i++){
            int rigMax = 0;

            for(int j=i+1;j<nums.size();j++){
                rigMax = max(rigMax,nums[j]);
            }

            if(nums[i]>lefFarMax || nums[i]>rigMax){
                ans.push_back(nums[i]);
            }
            lefFarMax = max(lefFarMax,nums[i]);
        }

        // if(nums.size()>1){
        //     ans.push_back(nums[nums.size()-1]);
        // }
        return ans;
    }
};