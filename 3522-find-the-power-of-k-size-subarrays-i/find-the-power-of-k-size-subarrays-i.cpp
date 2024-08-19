class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;

        for(int i=0;i<=nums.size()-k;i++){
            bool fl = true;
            int maxElem = nums[i];
            for(int j=i+1;j<i+k;j++){
                if(nums[j-1]+1 != nums[j]){
                    fl = false;
                    break;
                }
                else{
                    maxElem = max(maxElem,nums[j]);
                }
            }
            if(fl){
                ans.push_back(maxElem);
            }
            else{
                ans.push_back(-1);
            }
        }

        return ans;
    }
};