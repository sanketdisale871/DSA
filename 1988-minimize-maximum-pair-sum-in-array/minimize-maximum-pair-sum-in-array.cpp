class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int i=0,j=nums.size()-1;
        int maxiSum = 0;

        while(i<j){
            int crSum = nums[i]+nums[j];
            maxiSum = max(maxiSum,crSum);
            i++;
            j--;
        }
        return maxiSum;
    }
};