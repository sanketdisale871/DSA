class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;

        for(int i=0,cons=1;i<nums.size();i++){
            if(i && nums[i]==nums[i-1]+1){
                cons++;
            }
            else{
                cons = 1;
            }

            if(i+1>=k){
                if(cons>=k){
                    ans.push_back(nums[i]);
                }
                else{
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};