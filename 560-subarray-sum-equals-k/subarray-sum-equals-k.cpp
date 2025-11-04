class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>um;

        um[0]=1;

        int prefSum = 0;
        int noOfSub = 0;

        for(int i=0;i<nums.size();i++){
            prefSum+=nums[i];

            int res = prefSum-k;
            noOfSub+=um[res];

            um[prefSum]++;
        }
        return noOfSub;
    }
};