class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);

        int posInd = 0;
        int negInd = 1;

        for(auto it:nums){
            if(it<0){
                ans[negInd]=it;
                negInd+=2;
            }
            else{
                ans[posInd]=it;
                posInd+=2;
            }
        }

        return ans;
    }
};