class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int totNums= nums.size();

        int maxiSumTillNow=nums[0];
        int currSubSumAsc=nums[0];

        for(int trav=1;trav<totNums;trav++){
                if(nums[trav]>nums[trav-1]){
                    currSubSumAsc+=nums[trav];
                }
                else{
                    currSubSumAsc=nums[trav];
                }
            maxiSumTillNow = max(maxiSumTillNow,currSubSumAsc);
        }

        return maxiSumTillNow;
    }
};